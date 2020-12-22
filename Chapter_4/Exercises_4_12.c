#include <stdio.h>
#include <stdlib.h>

/*Write itoa in recursive version */

#define MAXLINE 1000

void itoa(char line[], int number);

int main(){

    char line[MAXLINE];

    int number = -5784;
    itoa(line, number);

    printf("itoa line: %s\n", line);

}

void itoa (char line[], int number){

    static int i;
    
    if (number / 10){
        itoa(line, number / 10);
    }
    else{
        i = 0;
        if(number < 0){
            line[i++] = '-';
        }
    }
    line[i++] = abs(number % 10) + '0';
    line[i] = '\0';
}

