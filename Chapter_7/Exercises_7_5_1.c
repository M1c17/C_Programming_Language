#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define STACKSIZE 100
#define MAXOP 100
#define NUMBER 'O'


/*
Rewrite the postfix rudimentary calculator to use scanf or sscanf to do the input and
number conversion.
*/

void push(int );
int pop();
int get_op(char *);

int main(){
    int type, op2;
    char s[MAXOP];

    while ((type = get_op(s)) != EOF){
        switch (type)
        {
        case NUMBER:
            push(atoi(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 == 0){
                printf("Zero division error\n");
            }
            push(pop() / op2);
            break;
        case '%':
            op2 = pop();
            if (op2 == 0){
                printf("Zero division error\n");
            }
            push((int)pop() % (int)op2);
            break;
        case '\n':
            printf("result = %d\n", pop());
            break;
        default:
            printf("Unknow character\n");
            break;
        }
    }
    return 0;
}

int sp = 0;
int stack[STACKSIZE];

void push(int c){
    if (sp > STACKSIZE){
        printf("push: cannot push element\n");
    }
    else{
        stack[sp++] = c;
    }
}
int pop(){
    if (sp > 0){
        return stack[--sp];
    }
    else{
        printf("pop: empty stack\n");
        return 0;
    }
}
int get_op(char *s){
    char input, r_input;
    float f;

    while ((r_input = scanf("%c", &input)) != EOF){
        if ((s[0] = input) != ' ' && input != '\t'){
            break;
        }
    }
    s[1] = '\0';

    if (r_input == EOF){
        return EOF;
    }
    else if (!isdigit(input) && input != '.'){
        return input;
    }
    ungetc(input, stdin);
    scanf("%f", &f);
    sprintf(s, "%f", f);
    return NUMBER;
}