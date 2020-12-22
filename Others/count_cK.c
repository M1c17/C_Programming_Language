#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

/*
Write a program to count the ocurrences of each C keyword
*/

#define NKEYS (sizeof keytab / sizeof(struct key))
//or 
//#define NKEYS (sizeof keytab / sizeof keytab[0])
#define BUFSIZE 100
#define MAXWORD 100

// char *keyword[NKEYS];               // arr holding names
// int keycount[NKEYS];                // arr of int for the counts

/*
number of keywords is the size of the array divided of the size of one element 
*/

/* reads the input by reapeatedly calling a function getword that fetches
one word at a time. 
*/
int main(){
    
    int n;
    char word[MAXWORD];

    while ((getword(word, MAXWORD)) != EOF){
        if (isalpha(word[0])){
            if ((n = binsearch(word, keytab, NKEYS)) > 0){
                keytab[n].count++;
            }
        }
    }
    for (n = 0; n < NKEYS; n++){
        if (keytab[n].count > 0){
            printf( "%4d %s\n", keytab[n].count, keytab[n].word );
        }
    }
    return 0;
}

// array of structures of pairs
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
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};


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

/* getword: get next word or character from input */
int getword(char *word, int maxword){
    int input;
    char *w = word;

    while (isspace(input = getch())){
        ;
    }

    for ( ; --maxword > 0 && input != EOF; ){
        *w++ = input;
        if (!isalpha(input)){
            *w = '\0';
            return input;
        }
        if (!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}


// Each word is looked up in keytab
int binsearch(char *word, struct key tab[], int n){
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high){
        mid = (low + high) /2;
        if((cond =  strcmp(word, tab[mid].word)) < 0){
            high = mid - 1;
        }
        else if((cond = strcmp(word, tab[mid].word)) > 0){
            low = mid + 1;
        }
        else{
            return mid;
        }
        return -1;
    }
}

