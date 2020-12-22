#include <stdio.h>

#define MAXLINE 1000

void squeeze(char s1[], char s2[]);

int main(){

    char s1[MAXLINE] = "abcde";
    char s2[MAXLINE] = "abc";

    squeeze(s1, s2);
    printf("new str: %s\n" , s1);

    return 0;

}

void squeeze(char s1[], char s2[]){
    int i, j, k;

    for (j = 0; s2[j] != '\0'; ++j){
        for (i = k = 0; s1[i] != '\0'; ++i){
            if (s1[i] != s2[j]){
                s1[k++] = s1[i];
            }
        }
        s1[k] = '\0';
    }
}

