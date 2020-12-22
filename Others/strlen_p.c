#include <stdio.h>

#define MAXLINE 100

int strlen_p(char *s);

int main(){

    char s[MAXLINE] = "could";
    printf("%d\n", strlen_p(s));

}

int strlen_p(char *s){
    char *p = s;

    while (*p != '\0'){
        p++;
    }
    return p - s;       //gives the number of char advance over 
}