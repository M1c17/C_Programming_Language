#include <stdio.h>

#define MAXLINE 1000

/* Write a program to remove trailing blanks and tabs 
from each line of input, and to delete enterely blanks line */

int get_line(char current_line[], int maxline);
void remove_trailing_blanks(char current_line[], int current_length);

//test it
int main(){

    //Ask for input 
    printf("Please, Enter a input and after that Ctrl + D:\n");
    //Initialize 
    int current_len;
    char current_line[MAXLINE];

    while ((current_len = get_line(current_line, MAXLINE)) > 0){

        printf("original_length: \n%d\n", current_len);
        remove_trailing_blanks(current_line, current_len);
        printf("This is the line: \n");
        printf("%s", current_line);
    }
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
    return i;
}

void remove_trailing_blanks(char current_line[], int current_len){
    int i;

    for (i = current_len - 2; current_line[i] == ' ' || current_line[i] == '\t'; -- i);
    current_line[i + 1] = '\n';
    current_line[i + 2] = '\0';
    printf("modify_length: \n%d\n", current_len);
}
