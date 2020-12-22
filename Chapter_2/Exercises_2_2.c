#include <stdio.h>

#define MAXLINE 1000

enum loop { NO, YES };
enum loop okloop = YES;

/* Write a for loop without using && or || */
//for(i = 0; i < MAXLINE -1 && (input = getchar()) != EOF && input != '\n'; ++i){
//    }

int main(){
    int input, i = 0;
    char line[MAXLINE];
    

    while(okloop == YES){
        if(i >= MAXLINE - 1){
            okloop = NO;
        }
        else if((input = getchar()) == EOF){
            okloop = NO;
        }
        else if(input == '\n'){
            okloop = NO;
        }
        else{
            line[i] = input;
            ++i;
        }      
    }
    line[i] = '\0';
    printf("line: %s\n", line);
    return 0;
}