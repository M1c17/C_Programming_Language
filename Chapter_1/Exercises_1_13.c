#include <stdio.h>

/* Write a program to print a histogram of the lengths of words 
its input. it is easy to draw the histogram with the bars horizontal; a 
vertical orientation is more challenging */

int main(){

    printf("Please, Enter a input and after that Ctrl + D:\n");
    int input, i, count_char = 0;

    //get input
    while((input = getchar()) != EOF){
        // Get a word until reach a blank
        if(input != ' ' || input != '\t' || input != '\n'){
            // count word
            ++count_char;
        }
        if(input == ' ' || input == '\t' || input == '\n'){
            // print histogram
            printf("%c",'|');
            for(i = 0; i < count_char - 1; ++i){
                printf("%c",'*');
            }
            printf("%c",'\n');
            count_char = 0;
        }
    }
}