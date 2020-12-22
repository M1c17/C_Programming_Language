#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int trim(char line[]);
int get_line(char line[], int maxline);


int main(){

    char line[MAXLINE];

    printf("Please, Enter input: \n");

    printf("original i: %d\n", get_line(line, MAXLINE));
    trim(line);
    printf("trim line: %s\n", line);
    printf("trim i: %d\n", trim(line));
    return 0;
    
}

int get_line(char line[], int maxline){
    int input, i;

    for (i = 0; i < maxline - 1 && (input = getchar()) != EOF; ++i){
        line[i] = input;
    }
    
    line[i] = '\0';
    return i;
}

/*remove blanks from the end of the line */
int trim(char line[]){
    int i = strlen(line) - 1;

    for ( ; i >= 0; i--){
        if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'){
            break;
        }
    }
    line[i+1] = '\0';
    return i;
}
