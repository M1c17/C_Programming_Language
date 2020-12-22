#include <stdio.h>

#define MAXLINE 1000

/* Write the function any => returns the first location in the string 
s1 where any char from the string s2 occurs, or -1 if s1 contains
no characters from s2. */

int get_line(char s[], int maxline);
int any(char s1[], char s2[]);


int main(){
    char s1[MAXLINE];
    char s2[MAXLINE];

    printf("Please, Enter first input: \n");
    get_line(s1, MAXLINE);
    printf("Please, Enter second input: \n");
    get_line(s2, MAXLINE);
    printf("new_line: \n%d\n", any(s1, s2));

}

int get_line(char s1[], int maxvalue){
    int input, i;

    for (i = 0; i < maxvalue - 1 && (input = getchar()) != '\0' && input != '\n'; ++i){
        s1[i] = input;
    }
    s1[i] = '\0';
    return i;
}

int any(char s1[], char s2[]){
    int i, j;

    for (j = 0; s2[j] != '\0'; ++j){
        for(i = 0; s1[i] != '\0'; ++i){
            if (s1[i] == s2[j]){
                return j;
            }
        }  
    }
    return -1;
}