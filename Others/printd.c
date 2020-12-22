#include <stdio.h>


void printd(int number);
/* convert a int to a str a print it */
int main(){

    int number = 1234;
    printd(number);
}

void printd(int n){
    if (n < 0){
        putchar('-');
        n = -n;
    }
    if (n / 10){
        printd(n / 10);
    }
    putchar(n % 10 + '0');
    printf("\n");
}

