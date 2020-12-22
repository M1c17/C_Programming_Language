#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define NO 0
#define MAXLINE 1000
#define TABINC 8

void settab(int argc, char *argv[], char *tab);
void entab(char *tab);
int tab_position(int position, char *tab);

int main(int argc, char *argv[]){

    char tab[MAXLINE];

    settab(argc, argv, tab);
    entab(tab);

    return 0;
}

int tab_position(int position, char *tab){
    if (position > MAXLINE){
        return YES;
    }else{
        return tab[position];
    }
}

void settab(int argc, char* argv[], char *tab){
    int i, position;

    if (argc <= 1){
        for (i = 0; i < MAXLINE; ++i){
            if (i % TABINC == 0){
                tab[i] = YES;
            }else{
                tab[i] = NO;
            }
        }
    }else{
        for (i = 0; i < MAXLINE; ++i){
            tab[i] = NO;
        }
        while (--argc > 0){
            position = atoi(*++argv);
            if (position > 0 && position <= MAXLINE){
                tab[position] = YES;
            }
        }
    }
}

void entab(char *tab){
    int i, input, position;
    int nb = 0;
    int nt = 0;

    for (position = 1; (input = getchar()) != EOF; ++position){
        //convert space in tab
        if (input == ' '){
            if (tab_position(position, tab) == NO){
                ++nb;
            }  
            else{
                nb = 0;
                ++nt;
            }
        }
        else{
            //print blanks 
            while (nt > 0){
                --nt;
                putchar('-');    
            }
            // check if tab else print space
            if (input == '\t'){
                nb = 0;
            }else{
                while (nb > 0){
                    --nb;
                    putchar('*');  
                }   
            }
            putchar(input);
            // check new line
            if (input == '\n'){
                position = 0;
            }
            // check tab after and before space
            else if (input == '\t'){
                while (tab_position(position, tab) != YES){
                    ++position;
                }
            }
        }
    }        
}


