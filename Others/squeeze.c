#include <stdio.h>
#define MAXLINE 1000

/*remove all ocurrence of c form s */

int get_line(char line[], int maxvalue);
void squeeze(char line[], char c);

int main(){

    char line[MAXLINE];
    char c = 'a';

    get_line(line, MAXLINE);
    squeeze(line, c);
    printf("new line: \n%s\n", line);
    
}

int get_line(char line[], int maxvalue){
    int input, i;

    for(i = 0; i < maxvalue - 1 && (input = getchar()) != EOF && input != '\n'; ++i){
        line[i] = input;
    }
    line[i] = '\0';
    return i;
}

void squeeze(char line[], char c){
    int i, j;

    for (i = j = 0; line[i] != '\0'; ++i){
        if (line[i] != c){
            line[j++] = line[i];
        }
    }
    line[j] = '\0';
}