#include <stdio.h>

#define MAXLINE 1000
/*Rewrite the function lower, which convert upper to lower, with
a conditional expression instead of if-else */

int * lower(char s[]);
int get_line(char s[], int maxline);

int main(){

    char s[MAXLINE];
    int * c;

    printf("Please. Enter input: \n");
    get_line(s, MAXLINE);
    c = lower(s);
    printf("new line: %c\n", *c);
    
}

int * lower(char s[]){
    int i;
    static int l[MAXLINE];

    for(i = 0; s[i] != '\0'; ++i){
        //printf("%c", s[i]);
        l[i] = (s[i] >= 'A' && s[i] <= 'Z' ? (s[i] + 'a'-'A') : s[i]);
    }
    return l;
}

int get_line(char s[], int maxline){
    int input, i;

    for(i = 0; i < maxline - 1 && (input = getchar()) != EOF && input != '\n'; ++i){
        s[i] = input;
    }
    s[i] = '\0';
    return i;
}