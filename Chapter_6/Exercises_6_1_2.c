#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

#define MAXWORD 100
#define BUFSIZE 100
#define NKEYS (sizeof keytab / sizeof keytab[0])

/* 
Write the keyword-counting program, this time using pointers insteas
of array indices 
*/

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

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);

/* count C keywords: pointer version */

int main(){

    char word[MAXWORD];
    struct key *p;

    while ((getword(word, MAXWORD)) != EOF){
        if (isalpha(word[0])){
            //printf("Word: %s\n", word);
            if ((p = binsearch(word, keytab, NKEYS)) != NULL){
                p->count++;
            }
        }
    }

    for (p = keytab; p < keytab + NKEYS; p++){
        if (p->count > 0){
            printf("%4d %s", p->count, p-> word);
        }
    }
    return 0;
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
        if ( input == '*'){
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
    char *w = word;
    int input, input2;

    while (isspace(input = getch())){
        ;
    }
    if (input != EOF){
        *w++ = input;
    }
    if (isalpha(input) || input == '-' || input == '#'){
        for ( ; --lim > 0; w++){
            if (!isalnum(*w = getch()) && *w != '-'){
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
    printf("Word: %s", word);
    return input;
}

struct key *binsearch(char *word, struct key *tab, int n){
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low < high){
        mid = low + (high-low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0){
            high = mid;
        }
        else if(cond > 0){
            low = mid + 1;
        }
        else{
            return mid;
        }
    }
    return NULL;
}
