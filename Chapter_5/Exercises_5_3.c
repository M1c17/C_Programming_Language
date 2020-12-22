#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Write a pointer version of the function strcat
strcat(s,t) copies the string t to the end of s */

void str_cat(char *s, char *t);

/* s must be big enough; pointer version */
int main()
{
    char s[100] = "First";
    char t[] = "Second";

    str_cat(s, t);

    printf("str1 : %s \n", s);
    printf("str2 : %s \n", t);

    return 0;
}


/*copies the string t to the end of s */
void str_cat(char *str, char *str2){

    // Find the end of s
    while((*++str) != '\0')
        ;

    // copy t to the end of s
    while((*str++ = *str2++) != '\0')
        ;
}
