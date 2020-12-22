#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

int getln(char line[], int maxline);
void copy(char to[], char from[]);

/*print longest input line */
int main(){

    printf("Please, Enter a input and after that Ctrl + D:\n");
    int current_len;        /* current line length */
    int longest_len;        /* longest line length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line save here */

    longest_len = 0;
    while((current_len = getln(line, MAXLINE)) > 0){
        if(current_len > longest_len) {
            //the longest line is the current line
            longest_len = current_len;
            //copy the new line to longest array
            copy(longest, line);
        }

        printf("line_length: %d\n", current_len);
    }
    if (longest_len > 0){      /*There is a line */
        printf("%s", longest);
    }
    return 0;
}

/* getline: read a line into s, return length */
//getline checks for overflow 
int getln(char line[], int maxline){
    int input, i;

    //conditions: less than maxline && no EOF and not the end of the line
    //without '\n' end => just characters
    for(i = 0; i < maxline - 1 && (input = getchar()) != EOF && input != '\n'; ++i){
        //save input into s[]
        line[i] = input;
    }
    //new line count 
    if (input == '\n'){
        //save input into s[]
        line[i] = input;
        ++i;
    }
    //'\0' the end of the string of characters 
    line[i] = '\0';
    //printf("line is: %d\n", i);
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
//copy can fin out how big the string are 
void copy(char to[], char from[]){
    int i = 0;
    while((to[i] = from[i]) != '\0'){
        ++i;
    }
}
