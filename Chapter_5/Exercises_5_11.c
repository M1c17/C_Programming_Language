#include <stdio.h>
#include <stdlib.h>


#define MAXLINE 100
#define TABINC 8
#define YES 1
#define NO 0



void detab(char *tab);
void set_tab(int argc, char *argv[], char *tab);
int tabposition(int position, char *tab);

int main(int argc, char *argv[]){

    char tab[MAXLINE];

    //Inititalize list tab stops
    set_tab(argc, argv, tab);
    //replace tabs with blanks
    detab(tab);
    return 0;
}


void set_tab(int argc, char *argv[], char *tab){
    int i, position;

    //since the user dont provide tab stop
    //TABINC default = 8
    if (argc <= 1){
        for (i = 0; i < MAXLINE; ++i){
            //is the position a multiple of TABINC
            if(i % TABINC == 0){
                //set flag to tab stops in array tab 
                tab[i] = YES;
            }else{
                tab[i] = NO;
            }
        }    
    }
    //user provide tab stop
    else{
        for (i = 0; i < MAXLINE; ++i){
            //turn off all tab stop
            tab[i] = NO;
        }
        //walk through argument list
        while(--argc > 0){
            //convert argument list provided (int to string)
            position = atoi(*++argv);
            if (position > 0 && position < MAXLINE){
                tab[position] = YES;
            }
        }
    }
}

int tabposition(int position, char *tab){

    if(position > MAXLINE){
        return YES;
    }else{
        return tab[position];
    }
}

/*write a program detab that replaces tabs in the input
 with the proper number of blanks to space to the next tab stop. */
 void detab(char *tab){

    int position = 1;   //position start up to found tab
    int input;

    while ((input = getchar()) != EOF){
        if (input == '\t'){
            //how many blanks do i need
            do{
                putchar('*');
            //if line is not at the end    
            }while(tabposition(position++, tab) != YES);
        }
        //end of line
        else if(input == '\n'){
            //putchar(input);
            position = 1;
        }
        //other characters
        else{
            putchar(input);
            ++position;   
        }
    }
}