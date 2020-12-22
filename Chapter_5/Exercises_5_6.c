#include <stdio.h>

#define MAXLINE 1000

/* getline: return len and store the input in array s. pointer version */*/
int get_line(char *s, int maxline);

int main(){
    char s[MAXLINE];
    get_line(s, MAXLINE);
    printf("new line: %s", s);

}

int get_line(char *s, int maxline){

    char *t = s;
    int input;

    while (--maxline > 0 && (input = getchar()) != EOF && input != '\n'){
        *s++ = input;
    }
    if (input == '\n'){
        *s++ = input;
    }
    *s = '\0';
    return s - t;

}