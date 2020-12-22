#include <stdio.h>

/* Write a program to copy its input to its output,
replacing each tab by \t, each backspace by \b, and each backslash by \\.
This makes tabs and backspaces visible in an unambiguos way. */

int main(){

    printf("Please, Enter a input and after that Ctrl + D:\n");
    char input;

    while((input = getchar()) != EOF){

        if(input == '\t'){
            putchar('\\');
            putchar('t');
        }
        else if(input == '\b'){
            putchar('\\');
            putchar('b');
        }
        else if(input == '\\'){
            putchar('\\');
            putchar('\\');
        }
        else
        {
            putchar(input);
        }   
    }
}