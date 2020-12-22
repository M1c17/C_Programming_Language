#include <stdio.h>
#include <ctype.h>

/* atoi: convert s to integer; pointer version */
int atoi(char *s);

int main(){

    char s[100] = "5346";

    printf("int: %d\n", atoi(s));
    //printf("s1: %c\n", *s);
    //printf("s2: %s\n", s);

}

int atoi(char *s){
    int sign, n;
    //skip blanks
    for( ; isspace(*s); s++){
        ;
    }
    sign = (*s == '-') ? -1 : 1;
    if (*s == '-' || *s == '+'){
        s++;
    }
    // convert
    for (n = 0; isdigit(*s); ++s){
        n = 10 * n + (*s - '0');
    }
    return sign * n;
}

