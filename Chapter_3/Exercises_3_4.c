#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

/*In a two's complement number representation our version of itoa
does not hadle the largest negative number, that is, tha value of 
n equal to - (2^wordsize -1). Explain why not. Modify it to print that
value correctly regardless of the machine on which it runs. */

void reverse(char line[]);
void itoa(int n, char line[]);

int main() {

    int n = -5897;
    char number_str[MAXLINE];

    itoa(n, number_str);
    printf("%s\n", number_str);

    return 0;
}


void reverse(char line[]){
    int i, j, temp;

    for (i = 0, j = strlen(line) - 1; i < j; ++i, --j){
        temp = line[i];
        line[i] = line[j];
        line[j] = temp;
    }
}
/* convert n int to characters in s */
void itoa(int n, char line[]){
    //Initialiaze variables 
    int i, sign;

    sign = (n < 0) ? -1 : 1;
    i = 0; 
    do {                                         //generate digits in reverse order
        line[i++] = sign * (n % 10) + '0';       //get next digit
    } while ((n /= 10) != 0);                    //delete it
    if (sign < 0){
        line[i++] = '-';
    }
    line[i] = '\0';
    reverse(line);   
}

/* OBS:
53 % 10 = 3 
53 / 10 = 5
5 / 10 = 0
% get the number of the last digit 
/ => will get rid of the last digit 
10 * n => get next int 

*/
