#include <stdio.h>

/*Write strcpy(s, t, n) copies at most n characters of t to s */

void str_ncpy(char *s, char *t, int n);
int str_len(char *);
void str_ncat(char *s, char *t, int n);

int main(){

    char s[100] = "First";
    char t[] = "Second";
    int n = 2;

    // str_ncpy(s, t, n);
    // printf("s str_ncpy: %s\n", s);
    str_ncat(s, t, n);
    printf("s str_ncat: %s\n", s);

}

void str_ncpy(char *s, char *t, int n){
    while (*t && n-- > 0){
        *s++ = *t++;
    }
    while (n-- > 0){
        *s++ = '\0';
    }
}

int str_len(char *s){
    int i;

    for(i = 0; *++s != '\0'; ++i){
        ;
    }
    return i;
}

void str_ncat(char *s, char *t, int n){ 
    unsigned int s_len = str_len(s);
    printf("len %d\n", s_len);
    s += s_len + 1;

    str_ncpy(s, t, n);
}