#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

/*Write a function of itoa that accept three arguments instead of two.
The third argument is a minimun field width; the converted number must be
padded with blanks on the left if necessary to make it wide enough*/

void reverse(char line[]);
void itoa(int n, char line[], int w);

int main(){

    int n = -53;
    int w = 8;
    char line[MAXLINE];

    itoa(n, line, w);
    printf("itoa line: %s\n", line);

}

void reverse(char line[]){
    int i, j, temp;
    int len = strlen(line);

    for(i = 0, j = len - 1; i < j; ++i, --j){
        temp = line[i];
        line[i] = line[j];
        line[j] = temp;
    }
}

void itoa(int n, char line[], int w){
    int i, sign;

    sign = n;
    i = 0;

    do
    {
        line[i++] = abs(n % 10) + '0';       //convert 
    } while ((n /= 10) != 0);           //delete from n
    if(sign < 0){
        line[i++] = '-';
    }
    while (i < w){
        line[i++] = '*';
    }
    line[i] = '\0';
    reverse(line);
}