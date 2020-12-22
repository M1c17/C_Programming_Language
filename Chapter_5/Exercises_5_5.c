#include <stdio.h>

/*Write strcpy(s, t, n) copies at most n characters of t to s */

void str_ncpy(char *s, char *t, int n);
int main(){
    char s[100] = "First";
    char t[] = "Second";
    int n = 2;

    str_ncpy(s, t, n);
    printf("line s: %s\n", s);

}

void str_ncpy(char *s, char *t, int n){

    for (n-- ; (*s++ = *t++) != '\0' && n != 0; n--){
        ;
    }
    //if t has few elements than n we pad the string with '\0'
    *s++ = '\0';
}