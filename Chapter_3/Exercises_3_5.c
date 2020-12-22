#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

/*Write the function itob(n,s,b) that converts the integer n
into a base b character representation in the string s.
In particular itob(n,s,16) formats n as hexadecimal integer in s.*/

void itob(int n, char line[], int base);
void reverse(char line[]);

int main(){

    int n = 15;
    char line[MAXLINE];

    itob(n, line, 16);
    printf("itob line: %s\n", line);
    return 0;

}

void reverse(char line[]){
    int i, j, temp;
    int len = strlen(line);

    for (i = 0, j = len - 1; i < j; ++i, --j){
        temp = line[i];
        line[i] = line[j];
        line[j] = temp;
    }
}


void itob(int n, char line[], int base){
    int i, j, sign;

    sign = n;
    i = 0;
    do
    {
        j = abs(n % base);                           //converto to base b
        line[i++] = (j <= 9) ? j+'0' : j+'a'- 10;    //convert to hexadecimal 
    } while ((n /= base) != 0);                      //delete the number from n 
    switch (base)
    {
    case 16:
        line[i++] = 'x';
        line[i++] = '0';
        break;
    }
                                
    if (sign < 0){
        line[i++] = '-';
    }
    line[i] = '\0';
    reverse(line);
}

