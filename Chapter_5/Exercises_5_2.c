#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define MAXLINE 1000

/* write the function getfloat 
return 0 if not found
       positive value and negative value */

int getch(void);
void ungetch(int f);
int getfloat(float *pf);

int main(){

    float array[MAXLINE];
    int i;

    for (i = 0; i < MAXLINE - 1 && getfloat(&array[i]) != EOF; ++i){
        printf("n: %f\n", array[i]);
    }
    return 0;
}

int buf_pos = 0;
int buffer[BUFSIZE];

int getch(void){
    return (buf_pos > 0) ? buffer[--buf_pos] : getchar();
}
void ungetch(int f){
    if(buf_pos >= BUFSIZE){
        printf("Error: stack is full");
    }
    buffer[buf_pos++] = f;
}

int getfloat(float *pf){
    int i, input, sign;
    float power;

    while (isspace(input = getch())){
        ;
    }
    if (!isdigit(input) && input != EOF && input != '+' && input != '-' && input != '.'){
        ungetch(input);
        return 0;
    }
    sign = (input == '-') ? -1 : 1;
    if (input == '+' || input == '-'){
        input = getch();
    }
    for(*pf = 0; isdigit(input); input = getch()){
        *pf = 10 * *pf + (input - '0');
    }
    if (input == '.'){
        input = getch();
    }
    for(power = 1.0; isdigit(input); input = getch()){
            *pf = 10.0 * *pf + (input - '0');
            power *= 10.0;
    }
    *pf *= sign / power;
    if (input != EOF){
        ungetch(input);
    }
    return input;
}