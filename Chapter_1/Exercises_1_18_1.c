#include <stdio.h>

#define MAXLINE 1000

/* Write a program to remove trailing blanks and tabs 
from each line of input, and to delete enterely blanks line */

int get_line(char current_line[], int maxline);
int remove_trailing_blanks(char current_line[]);

//test it
int main(){

    //Ask for input 
    printf("Please, Enter a input and after that Ctrl + D:\n");
    //Initialize 
    int current_len;
    char current_line[MAXLINE];

    while ((get_line(current_line, MAXLINE)) > 0){

        if(remove_trailing_blanks(current_line) > 0){
            printf("This is the line: \n");
            printf("%s", current_line);
        }    
    }
    return 0;
}
//get input 
int get_line(char current_line[], int maxline){
    // Initialize
    int input, i;

    for (i = 0; i < maxline - 1 && (input = getchar()) != EOF && input != '\n'; ++i){
        current_line[i] = input;
    }
    if (input == '\n'){
        current_line[i] = input;
        ++i;
    }
    current_line[i] = '\0';
    printf("original_len: \n%d\n", i);
    return i;
}

int remove_trailing_blanks(char current_line[]){
    int i = 0;
    while (current_line[i] != '\n'){
        ++i;
    }
    --i;            //back off from '/n'
    while (i >= 0 && (current_line[i] == ' ' || current_line[i] == '\t')){
        --i;
    }
    if (i >= 0){    //it is a non-blank line?
        ++i;
        current_line[i] = '\n';     //put newline char back
        ++i;
        current_line[i] = '\0';     //put end of the string
    }
    printf("modify_len: \n%d\n", i);
    return i;
}
