#include <stdio.h>
#include <stdlib.h>

#define DEFAULTAB 8
#define MAXLINE 100

/*Extend entab and detab to accept the shorthand
    entab -m +n
to mean tab stops every n columns, starting at column m.
Choose convenient (for the user) default behavior */

/* 
The value of m and n depends on the first character of arguments commands
if the first character is a '-' the integer after is m;
if the first character is a '+' the integer after is n;
*/

void detab(int m, int n);

int main(int argc, char *argv[]){
    int input;
    int n = DEFAULTAB, m = 0;

    while(--argc > 0){
        input = (*++argv)[0];
        switch (input)
            {
            case '-':
                m = atoi(++argv[0]);
                break;
            case '+':
                n = atoi(++argv[0]);
                break;
        }
    }
    detab(m, n);
    return 0;
}

void detab(int m, int n){

    int i = 0, j, input, position = 1;
    int TABINC;
    int nb = 0;
    char line[MAXLINE];
    int col =1;


    while ((input = getchar()) != EOF){
        if (input == '\t'){
            if (position <= m + n){
            TABINC = m + n;
            }
            else{
                // walk through the line
                for (j = 1; position > m + n + (j * n); j++){
                    ;
                }
                TABINC = m + n + (j * n);
            }
            nb = TABINC - ((position - 1) % TABINC);

            while (nb > 0){
                line[i++] = '*';
                --nb;

                if (i == MAXLINE - 1){
                    line[i] = '\0';
                    printf("%s", line);
                    position = 1;
                }
                ++position;
            }
        }
        else {
            line[i++] = input;
            ++position;
        }
        if (input == '\n'){
            position = 1;
        }

        if(i == MAXLINE - 1){
            line[i] = '\0';
            printf("%s", line);
            i = 0;
        }
    }
    line[i] = '\0';
    printf("%s", line);
}

