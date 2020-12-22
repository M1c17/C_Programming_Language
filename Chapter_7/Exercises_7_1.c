#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
Write a program that converts upper cases into lower cases 
or lower cases in to upper cases, depending on the name it 
is invoked with, as found in argv[0].
*/

void error(char *);

int main(int argc, char *argv[]){
    int input;

    if (argc < 2){
        error("Please, insert argument command");
    }
    else if (strcmp(argv[1], "lower") != 0 && strcmp(argv[1], "upper") != 0){
        error("Usage: nedded lower or upper arg command");
    }

    if (strcmp(argv[1], "lower") == 0){
        while ((input = getchar()) != EOF){
            putchar(tolower(input));
        }
    }
    else{
        while((input = getchar()) != EOF){
            putchar(toupper(input));
        }
    }
    return 0;
}

void error(char *s){
    printf("Error: %s\n", s);
}