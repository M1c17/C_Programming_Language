#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> 

#define STACKSIZE 100
#define MAXOP 1000
#define NUMBER '0'
#define BUFSIZE 1000
#define MAXLINE 1000


/*Write the program expr, which evaluate a polish reverse expression from the 
command line, where each operator or operant is a separate argument. */

void push(double n);
double pop(void);
void ungetch(int input);
void ungets(char s[]);
int get_op(char line[]);

int main(int argc, char *argv[]){

    char s[MAXOP];
    int type;
    double temp;

    if(argc <= 1){
        printf("Error need more than one argument");
        return 1;
    }

    while (--argc > 0){
        //push end of argument
        ungets(" ");
        //push an argument
        ungets(*++argv);
        switch (get_op(s))
        {
            case NUMBER:
                push(atof(s));
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
                if (temp == 0){
                    push(pop() / temp);
                }else{
                    printf("Zero division error\n");
                }
                break;
            default:
                printf("Unknow command type\n");
            break;
        }
    }
    printf("\t%.8g\n", pop());
    return 0;
}

        
int sp = 0;
double stack[STACKSIZE];

void push(double n){
    if (sp > STACKSIZE){
        printf("Error: stack full, can't push %g\n", n);
    }else{
        stack[sp++] = n;

        // stack[sp] = n;
        // sp++;
    }
}


double pop(void){
    if (sp > 0){
        return stack[--sp];
    }else{
        printf("Error: empty stack\n");
        return 0.0;
    } 
}

int bufpos = 0;
char buffer[BUFSIZE];

void ungetch(int input){
    if(bufpos >= BUFSIZE){
        printf("Error: buffer full\n");
    }else{
        buffer[bufpos++] = input;
    }
}

double getch(void){
    return (bufpos > 0)? buffer[--bufpos] : getchar();
}
    
void ungets(char s[]){
    int i;

    for(i = strlen(s) - 1; i >= 0; --i){
        ungetch(s[i]);
    }
}

int get_op(char s[]){
    int i, input;
    i = 0;

    while ((s[0] = input = getch()) == ' ' || input == '\t'){
        ;
    }
    s[1] = '\0';
    if (!isdigit(input) && input != '.'){
        return input;
    }
    if (isdigit(input)){
        while (isdigit(s[++i] = input = getch())){
            ;
        }
    }

    if (input == '.'){
        while (isdigit(s[++i] = input = getch())){
            ;
        }
    }
    return NUMBER;
}