#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char s[]);

int main(){

    char s[MAXLINE];
    strcpy(s, "this is a prove");
    reverse(s);
    printf("reverse line: %s\n", s);
    
}

void reverse(char s[]){
    int temp, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
        //printf("%lu/n", strlen(s) - 1);
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}