#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define STACKSIZE 100
#define NUMBER '0'

/*Write the program expr, which evaluate a polish reverse expression from the 
command line, where each operator or operant is a separate argument. */

void push(double f);
double pop();
void clear(void);

int main(int argc, char *argv[]){

    int input, type;
    double temp, temp1;

    while (--argc > 0){
        //*++argv;
        if (!isdigit(input = **++argv) && strlen(*argv) == 1){
            type = input;
        }else{
            type = NUMBER;
        }
        switch (type)
        {
        case NUMBER:
            push(atof(*argv));
            break;
        case '+':
            push(pop() + pop());
            break;
        case 'x':
            push(pop() * pop());
            break;
        case '-':
            temp = pop();
            push(pop() - temp);
            break;
        case '/':
            temp = pop();
            if (temp == 0.0){
                printf("Zero error division");
            }else{
                push(pop() / temp);
            } 
            break;
        case '%':
            temp = pop();
            if (temp == 0.0){
                printf("Zero division error");
            }else{
                push(fmod(pop(), temp));
            } 
            break;
        case '^':
            temp = pop();
            temp1 = pop();
            if(temp == 0.0 || temp1 == 0){
                printf("Error: if x is 0.0 y must be greater than 0.0\n");
            }else{
                push(pow(temp, temp1));
            }
            break;
        case 'e':
            push(exp(pop()));
            break;
        
        default:
            printf("Unknow command line %g\n", pop());
            break;
        }
    }
    printf("result = %g\n", pop());
}

int sp = 0;
char stack[STACKSIZE];

void clear(void){
    sp = 0;
}

void push(double f){
    if (sp > STACKSIZE){
        printf("Error: stack full, cannot push %g\n", f);
    }else{
        stack[sp++] = f;
    }
}
double pop(){
    if (sp > 0){
        return stack[--sp];
    }else{
        printf("Error: empty stack\n");
        return 0.0;
    }
}