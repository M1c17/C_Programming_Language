#include <stdio.h>

/*Write strncat(s,t,n) concatenate at most n char into s */

void str_ncat(char *s, char *t, int n);

int main(){

    char s[100] = "String";
    char t[] = "end";
    int n = 1;

    str_ncat(s, t, n);
    printf("line s: %s\n", s);
}

void str_ncat(char *s, char *t, int n){
    //Find end of s
    while (*++s != '\0'){
        ;
    }
    //copy t to the end of s when n is not 0 
    for (n--; (*s++ = *t++) != '\0' && n > 0 && *t != '\0'; --n){
        ;
    }
    *s++ = '\0';
}
