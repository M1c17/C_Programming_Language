#include <stdio.h>

#define MAXLINE 1000
#define TRUE (1==1)
#define FALSE !TRUE

/*Write a program to remove all comments from a C program
Don't forget to handle quoted string and characters contants properly.*/


void remove_comments(char current_line[], char without_comment[]);
int get_line(char current_line[], int maxline);


int main(){
    char current_line[MAXLINE];
    char without_comment[MAXLINE];

    printf("Please, Enter a input and after that Ctrl + D:\n");
    get_line(current_line, MAXLINE);
    remove_comments(current_line, without_comment);
    printf("line without comments: \n%s\n", without_comment);
    return 0;

}

int get_line(char current_line[], int maxline){
    int input, i;

    for(i = 0; i < maxline && (input = getchar()) != EOF && input != '\n'; i++){
        current_line[i] = input;
    }

    if (input == '\n'){
        current_line[i] = input;
        ++i;
    }
    current_line[i] = '\0';         //the end of the string 
    return i;
}

void remove_comments(char current_line[], char without_comment[]){
    int multiple_comment, single_comment, quote_str, i = 0, j = 0;

    quote_str = FALSE;
    single_comment = FALSE;
    multiple_comment = FALSE;

    while(current_line[i] != '\0'){
        if (!quote_str && current_line[i] == '"'){
            quote_str = TRUE;
        }
        else if (quote_str && current_line[i] == '"'){
            quote_str = FALSE;                          //end of quote
        }
        if (!quote_str){                                //any char
            if (current_line[i] == '/' && current_line[i+1] == '*' && !single_comment){
                multiple_comment = TRUE;
            }
            else if (current_line[i] == '*' && current_line[i+1] == '/'){
                multiple_comment = FALSE;
                i += 2;
            }
            if (current_line[i] == '/'){
                single_comment = TRUE;
            }
            if (current_line[i] == '\n'){
                single_comment = FALSE;
            }
            //count i
            if (single_comment || multiple_comment){
                ++i;
            }
            else{
                without_comment[j++] = current_line[i++];
            }
    }
     else{
         without_comment[j++] = current_line[i++];
    }
    without_comment[j] = '\0';                  //put the end of the string 
    }
                 
}