#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000

/*itoa: convert n to characters in s; pointer version. */

void itoa(int n, char *s);

int main(){

    int n = -23453;
    char s[MAXLINE];

    itoa(n, s);
    printf("itoa line: %s\n", s);

    return 0;

}

void reverse(char s[]){
    int temp;
    char *t;

    for (t = s + (strlen(s) - 1); s < t; s++, t--){
        temp = *s;
        *s = *t;
        *t = temp;
    }
}

void itoa(int n, char *s){

    int sign;
    char *t = s;

    sign = (n < 0)? -1 : 1;
    do
    {
        *s++ = sign * (n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0){
        *s++ = '-';
    }
    *s = '\0';
    reverse(t);             //point to the begining of array
}