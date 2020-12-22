#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#define MAXWORD 100
#define BUFSIZE 100

struct tnode{                           // the tree node
    char *word;                         // points to the text
    int count;                          // number of ocurrences
    struct tnode *left;                 // left child
    struct tnode *right;                // right child
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int );

/* word frequency count */
int main(){
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF){
        if(isalpha(word[0])){
            root = addtree(root, word);
        }
    }
    treeprint(root);
    return 0;
}

/* storge for the new node */
struct tnode *talloc(void){
    return (struct tnode *) malloc(sizeof(struct tnode));

}

/* strup: copies string given by its argument into a safe placed 
obtained by a call on malloc */
char *strd_up(char *s){           // make a duplicate of s
    
    char *p;

    p = (char *) malloc(strlen(s) + 1);         // +1 for end of str \0
    if (p != NULL){                             // malloc return NULL when no space is available
        strcpy(p, s);
    }
    return p;
}

/*add a node with w or at below p 
the word either matches something already in the tree (the count is incremented),
or a null pointer is encountered (a node must be created and added to the tree)
if a new node is created; adtree returns a pointer to it, which is installed
in the parent node
*/
struct tnode *addtree(struct tnode *p, char *w){
    int cond;

    if (p == NULL){
        p = talloc();
        p->word = strd_up(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    // repeated word
    else if((cond = strcmp(w, p->word)) == 0){
        p->count++;
    }
    else if(cond < 0){
        p->left = addtree(p->left, w);
    }
    else{
        p->right = addtree(p->right, w);
    }
    return p;
}
/*treeprint: in-order print of tree */
void treeprint(struct tnode *p){
    if (p != NULL){
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

int buf_pos = 0;
char buffer[BUFSIZE];

int getch(void){
    return (buf_pos > 0) ? buffer[--buf_pos] : getchar();
}

void ungetch(int c){
    if (buf_pos >= BUFSIZE){
        printf("ungetch: there are too many characters\n");
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
        }
        else{
            ungetch(input);
        }
    }
    return input;
}

int getword(char *word, int lim){
    int input, input2;
    char *w = word;

    while (isspace(input = getch())){
        ;
    }
    if (input != EOF){
        *w++ = input;
    }
    if (isalpha(input) || input == '_' || input == '#'){
        for ( ; --lim > 0; w++){
            if(!isalnum(*w = getch()) && *w != '_'){
                ungetch(*w);
                break;
            }
        }
    }
    else if(input == '\'' || input == '"'){
        for ( ; --lim > 0; w++){
            if ((*w = getch()) == '\\'){
                *++w = getch();
            }
            else if (*w == input){
                w++;
                break;
            }
            else if(*w == EOF){
                break;
            }
        }
    }
    else if(input == '/'){
        if ((input2 = getch()) == '*'){
            input = comment();
        }
        else{
            ungetch(input2);
        }
    }  
    *w = '\0';
    //printf("Word: %s\n", word);
    return input;
}

