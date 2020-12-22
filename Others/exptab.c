#include <stdio.h>
#define MAX 15
#define TABINC 8
/* Exptab: expand tab into blanks 
input : int -> position output : int -> position */

int main(){
    int input, pos, i;
    char line[MAX];

    while ((input = getchar()) != EOF){
        if (input == '\t'){
            line[pos] = '*';        // Initiate the tab with first space
            for (pos = 1; pos < MAX && pos % TABINC != 0; ++pos){
                line[pos] = '*';
            }
        }
        for (i = 0; i < pos; ++i){
            putchar(line[i]);
        }
        pos = 0;
        if (input == '\t'){
            putchar(line[pos+1]);
        }
        putchar(input);
    }
}