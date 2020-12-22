#include <stdio.h>

/* Write a program to count blanks, tabs and newlines. */

int main(){

    printf("Please, Enter input: ");
    int input, count;
    count = 0;

    while((input = getchar()) != EOF){
        if(input == ' ' || input == '\n' || input == '\t'){
            ++count;
        }
    }
    printf("count: %d\n", count);
}