#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFSIZE 100
#define STACKSIZE 100
#define MAXOP 100
#define NUMBER '0'

/*getop : get next operator or numeric operand. pointer version */

void push(int n);
int pop(void);
int getch(void);
void ungetch(int n);
int getop(char *s);

int main(){

    char s[MAXOP];
    int type, temp;

    while ((type = getop(s)) != EOF){
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            temp = pop();
            push(pop() - temp);
            break;    
        case '/':
            temp = pop();
            if (temp != 0){
                push(pop() / temp);
            } else {
                printf("Zero division error\n");
            }
            break;
        case '\n':
            printf("result = %d\n", pop());
        default:
            printf("Unknow character\n");
            break;
        }
    }
    return 0;
}

int s_p = 0;
char stack[STACKSIZE];

void push(int n){
    if(s_p > STACKSIZE){
        printf("Error: no space in stack\n");
    }else{
        stack[s_p++] = n;
    }

}
int pop(void){
    if(s_p > 0){
        return stack[--s_p];
    }else{
        printf("Error: empty stack\n");
        return 0.0;
    }
}

int buf_pos = 0;
int buffer[BUFSIZE];

int getch(void){
    return (buf_pos > 0)? buffer[--buf_pos] : getchar();
}
void ungetch(int input){
    if(buf_pos >= BUFSIZE){
        printf("Error: no space\n");
    }
    else{
        buffer[buf_pos++] = input;
    }
}

int getop(char *s){

    int input;

    //skip blanks
    while((*s = input = getch()) == ' ' || input == '\t'){
        ;
    }
    *(s+1) = '\0';
    if (!isdigit(input) && input != '.'){
        return input;
    }
    if (input == '.'){
        while (isdigit(*++s = input = getch())){
            ;
        }
    }

    if (isdigit(input)){
        while (isdigit(*++s = input = getch())){
            ;
        }
    }
    *s = '\0';
    if (input != EOF){
        ungetch(input);
    }
    return NUMBER;
}



