#include <stdio.h>
#include <stdlib.h>

#define TABINC 8
#define MAXLINE 100
#define YES 1
#define NO 0

void set_tab(int argc, char *argv[], char *tab);
void detab(char *tab);
int tab_position(int position, char *tab);

int main(int argc, char *argv[]){

    char tab[MAXLINE];

    set_tab(argc, argv, tab);
    detab(tab);

    return 0;

}

int tab_position(int position, char *tab){

    if (position > MAXLINE){
        return YES;
    }
    else{
        return tab[position];
    }
}

void set_tab(int argc, char *argv[], char *tab){
    int i, position, increment;

    if (argc <= 1){
        for (i = 1; i <= MAXLINE; i++){
            if(i % TABINC ==  0){
                tab[i] = YES;
            }
            else{
                tab[i] = NO;
            }
        }
    }
    else if(argc == 3 && *argv[1] == '-' && *argv[2] == '+'){
        printf("%c", *argv[1]);
        printf("%c", *argv[2]);
        position  = atoi(&(*++argv)[1]);
        printf("pos1: %d\n", position);
        increment = atoi(&(*++argv)[1]);
        printf("inc: %d\n", increment);
        for (i = 1; i <= MAXLINE; i++){
            if(i != position){
                tab[i] = NO;
            }
            else{
                tab[i] = YES;
                //printf("idx: %d, pos: %d\n", i, position);
                position += increment;
                //printf("idx: %d, pos: %d\n", i, position);
            }  
        }
        //printf("pos3: %d", position);
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
void detab(char *tab){

    int input, position = 1;

    while ((input = getchar()) != EOF){
        if (input == '\t'){
            do
            {
                putchar('*');
                printf("pos: %d\n", position);
            } while (tab_position(position++, tab) != YES);
        }
        else if (input == '\n'){
            position = 1;
        }
        else{
            putchar(input);
            ++position;
        }
    }
}
