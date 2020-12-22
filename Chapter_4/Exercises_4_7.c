#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

/*Write a routine ungets(s) that will push back an entire string onto the input*/

#define BUFFERSIZE 100
#define MAXLINE 1000

void ungets(char s[]);
int getch(void);
void ungetch(int input);


int main(){
    char s[MAXLINE];
    char t[MAXLINE];
    int i = 0;

    while ((s[i++] = getch()) != '\n'){
        ;
    }

    printf("string s: %s\n", s);
    ungets(s);
    printf("ungets called\n");
    i = 0;
    while ((t[i++] = getch()) != '\n'){
        ;
    }
    printf("string s again %s", s);
    printf("str t %s", t);

    return 0;
}

int buf_pos = 0;
char buffer[BUFFERSIZE];

int getch(void){

    return (buf_pos > 0) ? buffer[--buf_pos] : getchar();
}
void ungetch(int input){
    if (buf_pos >= BUFFERSIZE){
        printf("Error: There are too many characters\n");
    }
    else{
        buffer[buf_pos++] = input;
    }
}

void ungets(char s[]){

    int i;
    
    for (i = strlen(s) - 1; i >= 0; --i){
        ungetch(s[i]);
    }
}