#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse_s(char line[]);

/*reads a line of input at a time, reversed it and print the reversed line */
int main(){
    //Ask for input 
    printf("Please, Enter a input and after that Ctrl + D:\n");
    //Initialize
    int input;
    char line[MAXLINE];

    while(get_line(line, MAXLINE) > 0){
        reverse_s(line);
        printf("%s", line);
    }
}

//get input and store string into array 
int get_line(char line[], int maxline){
    // Initialize
    int input, i;

    for (i = 0; i < maxline - 1 && (input = getchar()) != EOF && input != '\n'; ++i){
        line[i] = input;
    }
    if (input == '\n'){
        line[i] = input;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void reverse_s(char line[]){
    //Initialize
    int i = 0, j = 0;
    char temp;
    //loop through the characters and count original_len
    while (line[i] != '\0'){
        ++i;        /*len_of_string*/
    }
    --i;            /*take out in count '\0'*/
    if (line[i] == '\n'){
        --i;        /*take out in count '\n' */   
    }
    //reverse string
    while(j < i){
        temp = line[i];          /*variable temporal */
        line[i] = line[j];       /*swicht variables */
        line[j] = temp;
        --i;                    
        ++j;
    }
}