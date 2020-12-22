#include <stdio.h>
#include <ctype.h>

/*
Write a program that will print arbitrary input in a sensible way.
As a minimum, it should print non-graphic characters in octal or
hexadecimal according to local custom, and break long text lines 
*/

#define MAXLINE 100             // max number characters in a line
#define OCTLEN  6               // lenght of an octal value

int inc(int , int);

int main(){
    int input, pos;
    pos = 0;

    while ((input = getchar()) != EOF){
        if (iscntrl(input) || input == '\n'){
            pos = inc(pos, OCTLEN);
            printf(" \\%03o", input);
            if (input == '\n'){
                pos = 0;
                putchar('\n');
            }
        }
        else{
            pos = inc(pos, 1);
            putchar(input);
        }
    }
    return 0;
}

int inc(int pos, int n){
    if (pos + n < MAXLINE){
        return pos + n;
    }
    else{
        putchar('\n');
        return n;
    }
}