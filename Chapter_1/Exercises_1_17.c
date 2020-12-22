#include <stdio.h>

/* print all input line that are longer to 80 */

#define MAXLINE 1000
#define MAXLENGHT 10

int get_line(char line[], int maxline);

int main(){
    int current_len;
    char current_line[MAXLINE];

    //get line 
    while((current_len = get_line(current_line, MAXLINE)) > 0){
        if(current_len > MAXLENGHT){
            printf("Longest than 80: \n");
            printf("%s", current_line);
        }
    }
    return 0;
}

// get input, return length of string.
int get_line(char line[], int maxline){
    int input, i;

    //count the string and store input 
    for(i=0; i < maxline - 1 && (input = getchar()) != EOF && input != '\n'; ++i){
        line[i] = input;
    }
    //count also the new line 
    //store input 
    if(input == '\n'){
        line[i] = input;
        ++i;
    }
    //an end of string maker
    line[i] ='\0';
    return i - 1;
}


