#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/*
Write a cross-referencer that prints a list of all words in a document, and
for each word, a list of the line numbers on which it occurs.
Remove noise words like "the", "and" and so on.
*/

#define MAXWORD 100
#define BUFSIZE 100

struct linklist {               // link list of line numbers
    int n_line;
    struct linklist *ptr;
};

struct tnode {
    char *word;
    struct linklist *lines;
    struct tnode *left;
    struct tnode *right;
};

/*
Write a cross-referencer that prints a list of all words in a document, and,
for each word, a list of the line number on which it occurs. Remove noise 
words like "the", "and", and so on.
*/

void treeprint(struct tnode *);
int noiseword(char *);
int getword(char *, int );
struct tnode *addtree(struct tnode *, char *, int );
void addln(struct tnode *, int);

/*cross-referencer */
int main(int argc, char *argv[]){
    struct tnode *root;
    char word[MAXWORD];
}

void treeprint(struct tnode *p){

    struct linklist *temp;
    
    if (p != NULL){
        treeprint(p->left);
        printf("%10s: ", p->word);
        for (temp = p->lines; temp != NULL; temp = temp->ptr){
            printf("%4d ", temp->n_line);
        }
        printf("\n");
        treeprint(p->right);
    }
}

int noiseword(char *word){
    static char *noise_w[] = {
        "a",
        "an",
        "and",
        "are",
        "in",
        "is",
        "of",
        "or",
        "that",
        "the",
        "this",
        "to"   
    };
    int cond, mid;
    int low = 0;
    int high = sizeof(noise_w)/sizeof(char *) - 1;

    while (low <= high){
        mid = (low + high) / 2;
        if ((cond = strcmp(word, noise_w[mid])) < 0){
            high = mid - 1;
        }
        else if(cond > 0){
            low = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int buf_pos = 0;
char buffer[BUFSIZE];

int getch(void){
    return (buf_pos > 0)? buffer[--buf_pos] : getchar();
}

void ungetch(int c){
    if (buf_pos >= BUFSIZE){
        printf("ungetch: There are too many characters\n");
    }
    else{
        buffer[buf_pos++] = c;
    }
}

int comment(void){
    int input;

    while ((input = getch()) != EOF){
        if (input == '*'){
            if ((input = getch()) == '/'){
                break;
            }
            else{
                ungetch(input);
            }
        }
    }
    return input;
}

int getword(char *word, int lim){
    int input, input2;
    char *w = word;

    while (isspace(input = getch()) && != '\n'){
        ;
    }

    if (input != EOF){
        *w++ = input;
    }

    if (isalpha(input) || input == '_' || input == '#'){
        for ( ; --lim > 0; w++){
            if (!isalnum(*w = getch()) && *w != '_'){
                ungetch(*w);
                break;
            }
        }
    }
    else if (input == '\'' || input == '"'){
        for ( ; --lim > 0; w++){
            if ((*w = getch()) == '\\'){
                *++w = getch();
            }
            else if (*w == input){
                w++;
                break;
            }
            else if (*w == EOF){
                break;
            }
        }
    }
    else if (input == '/'){
        if ((input2 = getch()) == '*'){
            input = comment();
        }
        else{
            ungetch(input2);
        }
    }
    *w = '\0';
    return input;
}

struct tnode *talloc(void){
    return (struct tnode *)malloc(sizeof(struct tnode));
}

struct linklist *lalloc(void){
    return (struct linklist *)malloc(sizeof(struct linklist));
}

struct tnode *addtree(struct tnode *p, char *word, int n_lin){
    int cond;

    if (p == NULL){
        p = talloc();
        p->word = strdup(word);
        p->lines = lalloc();
        p->lines->n_line = n_lin;
        p->lines->ptr = NULL;
        p->left = p->right = NULL;
    }
    else if((cond =  strcmp(word, p->word)) == 0){
        addln(p, n_lin);
    }
    else if(cond < 0){
        p->left = addtree(p->left, word, n_lin);
    }
    else{
        p->right = addtree(p->right, word, n_lin);
    }
    return p;
}

/*
addln: add a line number to the linked list */
void addln(struct tnode *p, int n_lin){
    struct linklist *temp;

    temp = p->lines;
    //traverses the linked list looking for an ocurrence of the same line
    while (temp->ptr != NULL && temp->n_line != n_lin){
        temp = temp->ptr;
    }
    // if the line is not in the list, the routine adds the line number at
    // the end of the linked list
    if (temp->n_line != n_lin){
        temp->ptr = lalloc();
        temp->ptr->n_line = n_lin;
        temp->ptr->ptr = NULL;
    }
}