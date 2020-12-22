#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXLINE 1000

/*In a two's complement number representation our version of itoa
does not hadle the largest negative number, that is, tha value of 
n equal to - (2^wordsize -1). Explain why not. Modify it to print that
value correctly regardless of the machine on which it runs. */

void reverse(char line[]);
void itoa(int n, char line[]);

int main() {

    int n = INT_MIN;
    char number_str[MAXLINE];

    itoa(n, number_str);
    printf("%s\n", number_str);

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
/* convert n int to characters in s */
void itoa(int n, char line[]){
    //Initialiaze variables 
    int i, sign;

    sign = n;
    i = 0;
    do
    {
        line[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0){
        line[i++] = '-';
    }
    line[i] = '\0';
    reverse(line);      
}

/* 

*-(2^wordsize-1)
cannot be converted to a positive number as in 
n = -n
because the largest positive number in a two's complement representation 
is (2^wordsize -1) -1


*the abs finds the absolute value of n % 10. this avoid the 
-(2^wordsize -1) problem because only the result of the modulus
operator is made positive

*/
