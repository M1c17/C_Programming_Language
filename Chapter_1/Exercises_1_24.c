#include <stdio.h>

#define MAXLINE 1000
#define IN 1;
#define OUT 0;

/*Write a program to check a C program for syntax
errors like unbalanced parentheses, brackets and braces.
Dont forget about quotes, both and double, escape sequences 
and comments. */

int get_line(char current_line[], int maxline);
void check_syntax(char currrent_line[]);

int main(){
    char current_line[MAXLINE];
    printf("Please, Enter a input and after that Ctrl + D:\n");
    get_line(current_line, MAXLINE);
    check_syntax(current_line);
    return 0;
}

int get_line(char current_line[], int maxline){
    int input, i;

    for (i = 0; i < maxline - 1 && (input = getchar()) != EOF && input != '\n'; ++i){
        current_line[i] = input;
    }
    if (input == '\n'){
        ++i;
        current_line[i] = input;
    }
    current_line[i] = '\0';
    return i;
}
void check_syntax(char current_line[]){

    //Initialize
    int n_line = 1;

    int n_parentheses = 0;
    int n_brackets = 0;
    int n_braces = 0;

    int single_quote = OUT;
    int double_quote = OUT;

    int multiple_comment = OUT;
    int single_comment = OUT;

    int i = 0;
    while (current_line[i] != '\0'){

        //count parentheses, brackets and braces
        if (current_line[i] == '\n'){
            ++n_line;
        }
        if (current_line[i] == '('){
            ++n_parentheses;
        }
        else if(current_line[i] == ')'){
            --n_parentheses;
        }
        if (current_line[i] == '['){
            ++n_brackets;
        }
        else if(current_line[i] == ']'){
            --n_brackets;
        }
        if (current_line[i] == '{'){
            ++n_braces;
        }
        else if(current_line[i] == '}'){
            --n_braces;
        }
        //flag
        if(current_line[i] == '\'' && current_line[i - 1] != '\\' && !single_quote && !double_quote){
            single_quote = IN;
        }
        else if (current_line[i] == '\'' && current_line[i - 1] != '\\'){
            single_quote = OUT;
        }
        if(current_line[i] == '"' && current_line[i - 1] != '\\' && !double_quote && !single_quote){
            double_quote = IN;
        }
        else if(current_line[i] == '"' && current_line[i - 1] != '\\'){
            double_quote = OUT;
        }
        if (current_line[i] == '/' && current_line[i + 1] == '*' && !multiple_comment){
            multiple_comment = IN;
        }
        else if(current_line[i] == '*' && current_line[i + 1] == '/'){
            multiple_comment = OUT;
        }
        if (current_line[i] == '/' && current_line[i + 1] == '/' && !single_comment){
            single_comment = IN;
        }
        else if(current_line[i] == '\n'){
            single_comment = OUT;
        }
        ++i;
    }
    //print errors
    if(n_parentheses){
        printf("Error: parentheses.\n");
    }
    if(n_brackets){
        printf("Error: brackets.\n");
    }
    if(n_braces){
        printf("Error: braces.\n");
    }
    if(single_quote){
        printf("Error: single quote.\n");
    }
    if(double_quote){
        printf("Error: double quote.\n");
    }
    if(multiple_comment){
        printf("Error: multiple comment.\n");
    }
}