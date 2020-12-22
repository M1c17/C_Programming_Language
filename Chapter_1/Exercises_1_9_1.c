#include <stdio.h>

int main(){

    printf("Please, Enter a input and after that Ctrl + D:\n");
    char input;
    char last_char;

    while((input = getchar()) != EOF){
        if(input != ' ' || last_char != ' '){
            putchar(input);
        }
        last_char = input;
    }
    return 0;
}