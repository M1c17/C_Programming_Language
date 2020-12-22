#include <stdio.h>

#define MAXLINE 1000

/*Write a program that delete every charac in s1 that matches every char in s2 */

int get_line(char s1[], int maxline);
void delete_repeat(char s1[], char s2[]);

int main(){

    char s1[MAXLINE];
    char s2[MAXLINE];

    printf("Please, Enter first input: \n");
    get_line(s1, MAXLINE);
    printf("Please, Enter second input: \n");
    get_line(s2, MAXLINE);
    delete_repeat(s1, s2);
    printf("new_line: \n%s\n", s1);

}

int get_line(char line[], int maxline){
    int input, i;

    for (i = 0; i < maxline && (input = getchar()) != EOF && input != '\n'; ++i){
        line[i] = input;
    }
    line[i] = '\0';
    return i;
}
void delete_repeat(char s1[], char s2[]){
    int i, j, k;

    for(j = 0; s2[j] != '\0'; ++j){
        for(i = k = 0; s1[i] != '\0'; ++i){
            if (s1[i] != s2[j]){
                s1[k++] = s1[i];
            }
        }
        s1[k] = '\0';
    }
}