#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*Add commands to print the top element of the stack
without poping, to duplicate it, and to swap the top two
elements. Add a command to clear the stack */

#define MAXOP   100
#define MAXSTACK 100
#define BUFFERSIZE 100
#define NUMBER 'O'

void push(double f);
double pop(void);
int get_op(char stack[]);
void clear(void);


int main(){

    char s[MAXOP];
    int type;
    double op_2, op_1;


    while ((type = get_op(s)) != EOF){
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
            op_2 = pop();
            push(pop() - op_2);
            break;
        case '/':
            op_2 = pop();
            if (op_2 != 0.0){
                push(pop() / op_2);
            }
            break;
        case '%':
            op_2 = pop();
            if (op_2 != 0.0){
                push((int)pop() % (int)op_2);
            }
            else{
                printf("Zero division error\n");
            }
            break;
        //print the top element of the stack without poping,
        case '?':
            op_2 = pop();
            printf("top element stack: %g\n", op_2);
            push(op_2);
            break;
        //to duplicate it
        case 'd':
            op_2 = pop();
            push(op_2);
            push(op_2);
            break;
        //and to swap the top two elements
        case 's':
            op_1 = pop();
            op_2 = pop();
            push(op_1);
            push(op_2);
            break;
        //clear the stack
        case 'c':
            clear();
            break;
        case '\n':
            printf("result = %g\n", pop());
            break;
        default:
            printf("Error: Unknow character\n");
            break;
        }
    }
    return 0;
}

int stack_pos = 0;
double stack[MAXSTACK];

/*push elements into the stack */
void push(double f){
    if (stack_pos < MAXSTACK){
        stack[stack_pos++] = f;
    }
    else{
        printf("Error, the stack is full, cannot push %f\n", f);
    }
}

double pop(void){
    if (stack_pos > 0){
        return stack[--stack_pos];
    }
    else{
        printf("Error: the stack is empty\n");
        return 0.0;
    }
}

//clear stack
void clear(void){
    stack_pos = 0;
}

int buf_pos = 0;
char buffer[BUFFERSIZE];

int getch(void){

    return (buf_pos > 0) ? buffer[--buf_pos] : getchar();
}
void ungetch(int input){
    if (buf_pos >= BUFFERSIZE){
        printf("Error: There are too many characters\n");
    }
    else{
        buffer[buf_pos++] = input;
    }
}

int get_op(char s[]){
    //Initialize
    int input, i;
    i = 0;

    //skip white space and tabs
    while ((s[0] = input = getch()) == ' ' || input == '\t' ){
        ;
    }
    s[1] = '\0';
    if (!isdigit(input) && input != '.' && input != '-'){
        return input;
    }
    if (input == '-'){
         int next = getch();

        if (!isdigit(next) && next != '.'){
            return input;
        }
        input = next; 
    }
    else{
        input = getch();
    }
    if (isdigit(input)){
        //give me next //Is next digit ?
        while(isdigit(s[++i] = input = getch())){
            ;
        }
    }
    if (input == '.'){
        //give me next // Is next digit?
        while(isdigit(s[++i] = input = getch())){
            ;
        }
    }
    if (input != EOF){
        ungetch(input);
    }
    return NUMBER;
}