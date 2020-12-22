#include <stdio.h>

#define DECIMAL_VALUE 128

/* Write a program to print a histogram of the frequencies of the 
diferent charaters */

int main(){
    
    //Ask for input 
    printf("Please, Enter a input and after that Ctrl + D:\n");
    //Initialize variables
    int input, i;
    int char_frequencies[DECIMAL_VALUE];  //char counter

    //Initialize array of characters to 0
    for(i = 0; i < DECIMAL_VALUE; ++i){
        char_frequencies[i] = 0;
    }

    //get input
    while((input = getchar()) != EOF){
        //count characters
        ++char_frequencies[input];
    }
    printf("\n ASCII | COUNT\n");
    //print histogram
    for(i = 0; i < DECIMAL_VALUE; ++i){
        if(char_frequencies[i] > 1){        //dont count the null char.
            printf("%c : %5d\n ", i, char_frequencies[i]);
        }
    }
    return 0;
}
