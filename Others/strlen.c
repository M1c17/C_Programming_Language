#include <stdio.h>

#define MAXLINE 1000

int lenght(char str[]);

int main(){
    int input;
    char str[MAXLINE];
    int i;

    for(i = 0; i < MAXLINE && (input = getchar()) != EOF && input != '\n'; ++i){
        str[i] = input;
    }   
    printf("the len is: %d\n", lenght(str));
}

int lenght(char str[]){
    int i;
    i=0; 

    while (str[i] != '\0'){
        ++i;
    }
    return i;
}

