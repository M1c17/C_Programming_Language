#include <stdio.h>

/*Write a program to copy its input to its output,
replacing each string of one or more blanks by single blank. */

int main(){

    printf("Please, Enter a input and after that Ctrl + D:\n");
    int input, number_of_blanks;
    number_of_blanks = 0;

    while((input = getchar()) != EOF){
        if(input == ' '){
            ++ number_of_blanks;
        }
        if(input != ' '){
            if(number_of_blanks >= 1){
                putchar(' ');
                number_of_blanks = 0;
            }
            putchar(input);
        }
    }
}