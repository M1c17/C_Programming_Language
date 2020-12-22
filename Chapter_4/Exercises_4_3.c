#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP   100
#define MAXSTACK 100
#define BUFFERSIZE 100
#define NUMBER 'O'

void push(double f);
double pop(void);
int get_op(char stack[]);


int main(){

    char s[MAXOP];
    int type;
    double op_2;

    printf("here: %s\n", s);
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
            else{
                printf("Zero division error\n");
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
    // for (int n =0; n < 3; n++){
    //     printf("stack: %f\n", stack[n]);
    // }   
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
    printf("here: %s\n", s);

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

