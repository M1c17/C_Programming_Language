#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

#define NKEYS (sizeof keytab/ sizeof keytab[0])
#define MAXWORD 100
#define BUFSIZE 100

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "do", 0,
    "double", 0,
    "else", 0,
    "enum", 0,
    "extern", 0,
    "float", 0,
    "for", 0,
    "goto", 0,
    "if", 0,
    "int", 0,
    "long", 0,
    "register", 0,
    "return", 0,
    "short", 0,
    "signed", 0,
    "sizeof", 0,
    "static", 0,
    "struct", 0,
    "switch", 0,
    "typedef", 0,
    "union", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

int getword(char *, int );
int binsearch(char *, struct key *, int);

/*count C keywords */
int main(){

    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF){
        //printf("Word: %s\n", word);
        if(isalpha(word[0])){
            if ((n = binsearch(word, keytab, NKEYS)) >= 0){
                keytab[n].count++;
            }
        }
    }
    // print
    for (n = 0; n < NKEYS; ++n){
        if (keytab[n].count > 0){ 
            printf( "%4d %s\n", keytab[n].count, keytab[n].word );
        }  
    }
    return 0;
}

int buf_pos;
char buffer[BUFSIZE];

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* comment: skip over comments and return last character*/
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

int getword(char *word, int maxword){

    int input, input2;
    char *w = word;

    //skip space
   while (isspace(input = getch())){
        ;
    }
    if (input != EOF){
        *w++ = input;
    }
    //is letter, is underscore, is preprocessor
    if (isalpha(input) || input == '_' || input == '#'){
        for ( ; --maxword > 0; w++){
            //printf("Word: %s", word);
            if (!isalnum(*w = getch()) && *w != '_'){
                ungetch(*w);
                break;
            }
        }
    }
    // is a constant string
    else if(input == '\'' || input == '"'){
        for ( ; --maxword > 0; w++){
            if ((*w = getch()) == '\\'){
                *++w = getch(); 
            }
            else if(*w == input){
                w++;
                break;
            }
            else if(*w == EOF){
                break;
            }
        } 
    }
    // is comment? skip comments 
    else if (input == '/'){
        if ((input2 = getch()) == '*'){
            input = comment();
        }
        else{
            ungetch(input2);
        }
    }
    *w = '\0';
    printf("Word: %s\n", word);
    return input;
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n){
    int low, high, mid, comp;
    low = 0;
    high = n - 1;
     
    while (low <= high){
        mid = (low + high) / 2;

        if ((comp = strcmp(word, tab[mid].word)) < 0){
            high = mid - 1;
        }
        else if(comp > 0){
            low =  mid + 1;
        }
        else{
            //printf("here");
            return mid;
        }
    }
    return -1;
}

