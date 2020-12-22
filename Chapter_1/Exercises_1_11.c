#include <stdio.h>

#define IN 1;
#define OUT 0;

int main(){

    printf("Please, Enter a input and after that Ctrl + D:\n");
    int input, count_lines, count_char, count_word, state;

    while ((input = getchar()) != EOF){
        count_lines, count_char, count_word = 0;
        state = OUT;
        ++count_char;

        if(input == '\n'){
            ++count_lines;
        }
        if(input == ' ' || input == '\n' || input =='t'){
            state = OUT;
        }
        else if(state == OUT){
            state = IN;
            ++count_word;
        }
    }
    printf("Lines=%d\nwords=%d\nchar=%d\n", count_lines, count_words, count_characters);
}

/* How would you test the Word_count program?
Answer = its important to create test_cases scenaries
and corners to solve the problem to see if the program
is doing what it suppous to do. also the program should be 
time efficient, reliable, complexity.

What kinds of input are most likely to uncover bugs if there are any?
To uncover bug is important to test corners, special cases
all the input scenaries and their outputs */


