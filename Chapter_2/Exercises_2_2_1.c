#include <stdio.h>

#define MAXLINE 1000

/* Write a for loop without using && or || */
//for(i = 0; i < MAXLINE -1 && (input = getchar()) != EOF && input != '\n'; ++i){
//    }

int main(){
    char line[MAXLINE];

    int i;
    int input;

    while((input = getchar()) != EOF){
        if (i >= MAXLINE - 1){
            break;
        }
        if (input == '\n'){
            break;
        }
        line[i++] = input;
    }
    line[i] = '\0';
    printf("line: %s\n", line);
    return 0;
}
