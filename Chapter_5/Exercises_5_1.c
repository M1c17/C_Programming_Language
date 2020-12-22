#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define MAXLINE 1000

int getint(int *pn);
int getch(void);
void ungetch(int n);

/* getint : get next integer from input into *pn 
returns EOF for end of file, 0 is not a valid number, a positive
value if the input contains a valid number and a negative number
if it is valid */

int main(){
    int array[MAXLINE];
    int i;

    for (i = 0; i < MAXLINE - 1 && getint(&array[i]) != EOF; ++i){
        printf("i %d: n: %d\t", i, array[i]);;
    }  
    return 0;

}

int buf_pos = 0;
int buffer[BUFSIZE];

int getch(void){
    return (buf_pos > 0) ? buffer[--buf_pos] : getchar();
}

void ungetch(int n){
    if (buf_pos >= BUFSIZE){
        printf("Error: full stack\n");
    }
    buffer[buf_pos++] = n;
}

int getint(int *pn){

    int input, sign, temp;

    //skip blanks
    while (isspace(input = getch())){
        ;
    }
    if (!isdigit(input) && input != EOF && input != '+' && input != '-'){
        ungetch(input);
        return 0;
    }
    sign = (input == '-') ? -1 : 1;
    if (input == '+' || input == '-'){
        input = getch();
        // temp = input;
        // if (!isdigit(input = getch())){
        //     if(input != EOF){
        //         ungetch(input);
        //     }
        //     ungetch(temp);
        //     return temp;
        // }
    }
    for( *pn = 0; isdigit(input); input = getch() ){
        //transform int to string
        *pn = 10 * *pn + (input - '0');
    }
    *pn *= sign;
    if (input != EOF){
        ungetch(input);
    }
    return input;
}