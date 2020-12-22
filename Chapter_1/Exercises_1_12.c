#include <stdio.h>


/* Write a program that prints its input one word per line */

int main(){

    printf("Please, Enter a input and after that Ctrl + D:\n");

    char input;

    while((input = getchar()) != EOF){
        if(input == ' ' || input == '\n' || input == '\t'){
            putchar('\n');
        }
        putchar(input); 
    }
    return 0;
}