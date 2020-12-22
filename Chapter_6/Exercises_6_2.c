#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#define MAXWORD 100
#define BUFSIZE 100

enum { NO, YES };


/* 
Write a program that reads a C program and prints in alphabetical order
each group of variable names that are identical in the first 6 letters,
but different somewhere thereafter. Dont count words within strings and
comments. Make 6 a parameter that can be set from the command line
*/

struct tnode {
    char *word;
    int match;
    struct tnode *left;
    struct tnode *right;
};

int getword(char *, int);
struct tnode *treealloc(void);
char *strd_up(char *);
void treeprint(struct tnode *);
struct tnode *addtree(struct tnode *, char *, int, int *);
int compare(char *, struct tnode *, int , int *);


/* print in alphabetic order each group of variable names */
int main(int argc, char *argv[]){

    int num;
    char word[MAXWORD];
    struct tnode *root;
    int found = NO;

    root = NULL;
    num = (--argc && (*++argv)[0] == '_')? atoi(argv[0]+1) : 3;
    //printf("argv: %s\n", argv[0]+1);
    //printf("argv2: %s\n", argv[1]);
    
    while (getword(word, MAXWORD) != EOF){
        //printf("Word: %s", word);
        if (isalpha(word[0]) && strlen(word) >= num){
            root = addtree(root, word, num, &found);
        }
        found = NO;
    }
    treeprint(root);
    return 0;
}

int compare(char *word, struct tnode *p, int num, int *found){
    int i;
    char *t = p->word;

    for (i = 0; *word == *t; i++, word++, t++){
        if (*word == '\0'){
            return 0;
        }  
    }
    //printf("here1 %d\n", i);
    //printf("num: %d\n", num);
    if (i >= num){      //identical in first num of characters
        *found = YES;
        ///printf("here2 %d\n", i);
        p->match = YES;
    }
    return *word - *t;
}

struct tnode *treealloc(void){
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *strd_up(char *word){
    char *p;

    p = (char *)malloc(strlen(word) + 1);
    if (p != NULL){
        strcpy(p, word);
    }
    return p;
}

void treeprint(struct tnode *p){
    if (p != NULL){
        treeprint(p->left);
        if (p->match){
            printf("%4d, %s\n", p->match, p->word);
        }
        treeprint(p->right);
        printf("here: %s\n", p->word);
        printf("here2: %d\n", p->match);
    }
}
struct tnode *addtree(struct tnode *p, char *word, int num, int *found){
    int cond;

    if (p == NULL){
        p = treealloc();
        p->word = strd_up(word);
        p->match = *found;
        p->left = p->right = NULL;
    }
    else if ((cond = compare(word, p, num, found)) < 0){
        p->left = addtree(p->left, word, num, found);
    }
    else if (cond > 0){
        p->right = addtree(p->right, word, num, found);
    }
    return p;
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

    while (isspace(input = getch())){
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