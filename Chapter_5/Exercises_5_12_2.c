#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100
#define TABINC 8
#define YES 1
#define NO  0

void set_tab(int argc, char *argv[], char *tab);
int tab_position(int position, char *tab);
void entab(char *tab);


int main(int argc, char *argv[]){

    char tab[MAXLINE];

    set_tab(argc, argv, tab);
    entab(tab);

    return 0;

}

void set_tab(int argc, char *argv[], char *tab){

    int i, position, increment;

    if (argc <= 1){
        for (i = 1; i <= MAXLINE; i++){
            if (i % TABINC == 0){
                tab[i] = YES;
            }
            else{
                tab[i] = NO;
            }
        }
    }
    else if(argc == 3 && *argv[1] == '-' && *argv[2] == '+'){
        position = atoi(&(*++argv)[1]);
        increment = atoi(&(*++argv)[1]);
        for (i = 1; i <= MAXLINE; i++){
            if (i != position){
                tab[i] = NO;
            }
            else{
                tab[i] = YES;
                position += increment;
            } 
        }
    }
    else{

        for (i = 1; i <= MAXLINE; i++){
            tab[i] = NO;
        }
        while (--argc > 0){
            position = atoi(*++argv);
            if (position > 0 || position <= MAXLINE){
                tab[position] = YES;
            }
        }
    }
}

int tab_position(int position, char *tab){

    if (position > MAXLINE){
        return YES;
    }
    else{
        return tab[position];
    }
}
void entab(char *tab){

    int input, i, position;
    int nb = 0;
    int nt = 0;

    for (position = 1; (input = getchar()) != EOF; position++){
        if (input == ' '){
            if (tab_position(position, tab) != YES){
                ++nb;
            }
            else{
                nb = 0;
                ++nt;   
            }
        }
        else{
            while (nt > 0){
                --nt;
                putchar('-');   
            }
            if (input == '\t'){
                nb = 0;
            }
            else{
                while (nb > 0){
                    --nb;
                    putchar('*'); 
                }                  
            }
            putchar(input);
            if (input == '\n'){
                position = 0;
            }
            else if(input == '\t'){
                while (tab_position(position, tab) != YES){
                    ++position;
                }
            }
        }
    }
}



