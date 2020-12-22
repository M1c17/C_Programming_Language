#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void str_cat(char s1[], char s2[]);

int main(){

    char s1[MAXLINE];
    char s2[MAXLINE] = "end";

    get_line(s1, MAXLINE);
    str_cat(s1, s2);
    printf("new line: %s\n", s1);
}


int get_line(char line[], int maxline){
    int input, i;

    for(i = 0; i < maxline - 1 && (input = getchar()) != EOF && input != '\n'; ++i){
        line[i] = input;
    }
    line[i] = '\0';
    return i;
}

/* concatenate t to end of s; s must be big enough */

void str_cat(char s1[], char s2[]){
    int i, j;

    i = j = 0;
    while (s1[i] != '\0'){
        ++i;
    }
    while ((s1[i++] = s2[j++]) != '\0'){
        ;
    }
}
