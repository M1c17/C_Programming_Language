#include <stdio.h>
#include <stdlib.h>

#define DEFAULTTAB 8
#define MAXLINE 1000


/* Modify the programs entab to accept a list of tab stops arguments.
Use the default tab setting if there are no arguments */

void entab(int TABINC);

int main(int argc, char *argv[]){

    int tabstop = 0, TABINC;

    if (argc <= 1){
        TABINC = DEFAULTTAB;
    }

    while (--argc > 0){
        tabstop ++;

        if (tabstop){
            TABINC = atoi(*++argv);
            --tabstop;
        }
    }
    entab(TABINC);
    return 0;
}

void entab(int TABINC){

    int input,position;
    char line[MAXLINE];
    int nb = 0;
    int nt = 0;
    int i = 0;

    for(position = 1; (input = getchar()) != EOF; position++){
        //add tab when position % TABINC == 0
        if (input == ' '){
            if (position % TABINC != 0){
                ++nb;
            }else{
                nb = 0;
                ++nt;
            }

        }else{
            //print tabs and space according to TABINC
            for ( ; nt > 0; --nt){
                line[i] = '-';
                ++i;
                if (i == MAXLINE - 1){
                    line[i] = '\0';
                    printf("%s", line);
                    i = 0;
                }

            }
            if (input == '\t'){
                nb = 0;
            }
            else{
                for ( ; nb > 0; --nb){
                    line[i] = '*';
                    ++i;
                    if (i == MAXLINE -1){
                    line[i] = '\0';
                    printf("%s", line);
                    i = 0;
                    }
                }
            }
            //after print blanks and tabs print input charac
            line[i] = input;
            ++i;
            if (input == '\n'){
                //reset position
                position = 0;
            }
            else if(input == '\t'){
                position = position + (TABINC - (position -1) % TABINC) - 1;
            }
        }
    }
    line[i] = '\0';
    printf("%s", line);
}