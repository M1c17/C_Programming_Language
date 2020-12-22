#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define DEFAULTTAB 8

void detab(int TABINC);

int main(int argc, char *argv[]){

    int list_tabstops = 0;
    int TABINC;

    if (argc <= 1){
        TABINC = DEFAULTTAB;
    }

    while (--argc > 0){
        list_tabstops++;

        if (list_tabstops){
            TABINC = atoi(*++argv);
            --list_tabstops;
        }
    }
    detab(TABINC);   
    return 0;
}

void detab(int TABINC){
    //Initialize variables
    int input;
    char line[MAXLINE];
    int nb = 0;

    int i = 0;
    int position = 1;   //position up to found tab

    while ((input = getchar()) != EOF) {
        if (input == '\t'){
            nb = TABINC - (position - 1) % TABINC;
            while (nb > 0){
                line[i] = '*';
                ++i;
                --nb;

                if (i == MAXLINE - 1){
                    line[i] = '\0';
                    printf("%s", line);
                    position = 1;
                }
                ++position;
            }
        }
        else{
            line[i] = input;
            ++i;
            ++position;
        }

        if (input == '\n'){
            position = 1;
        }

        if (i == MAXLINE - 1){
            line[i] = '\0';
            printf("%s", line);
            i = 0;
        }
    }
    line[i] = '\0';
    printf("%s", line);           
}