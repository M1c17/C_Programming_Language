#include <stdio.h>

void strcpy_p(char *, char *);

int main(){

    char t[] = "hello";
    char s[] = " , world!'";
    strcpy_p(t, s);
    printf("t: %s\n", t);
    printf("s: %s\n", s);

}

/* copy t to s */
void strcpy_p(char *t, char *s){
    while ((*s++ = *t++) != '\0'){
        ;
        // ++s;
        // ++t;
    }
}