#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

/*Add commands for handling variables. (26 single letter names).
Add a variable for the most recently printed value. */


#define MAXOP   100
#define MAXSTACK 100
#define BUFFERSIZE 100
#define NUMBER 'O'
#define NAME   'n'

void push(double f);
double pop(void);
int get_op(char stack[]);
void clear(void);
void mathfunc(char s[]);


int main(){

    char s[MAXOP];
    int type, i, var;
    double op_2, op_1, v;
    double variable[26];

    //Initialize array variable
    for (i = 0; i < 26; ++i){
        variable[i] = 0.0;
    }

    while ((type = get_op(s)) != EOF){
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case NAME:
            mathfunc(s);
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
        //Assign an element from the stack to the preceding variable name
        case '$':
            //pop the variable
            pop();
            if (var >= 'A' && var <= 'Z'){
                variable[var - 'A'] = pop();        //pop the number assign to the variable
            }
            break;
        case '\n':
            //add lower case variable v that hold the last printed
            v = pop();
            printf("result = %g\n", v);
            break;

        //add Upper case letter from A to Z
        default:
            if (type >= 'A' && type <= 'Z'){
                //push into the stack
                push(variable[type -'A']);
            }
            else if(type == 'v'){
                push(v);
            }
            else{
                printf("Error: Unknow character\n");
            }
            break;
        }
        var = type;
    }
    return 0;
}
//sin, exp, and pow
void mathfunc(char s[]){
    double op_2;

    if (strcmp(s, "sin") == 0){
        push(sin(pop()));
    }
    else if (strcmp(s, "cos") == 0){
        push(cos(pop()));
    }
    else if (strcmp(s, "exp") == 0){
        push(exp(pop()));
    }
    else if (strcmp(s, "pow") == 0){
        op_2 = pop();
        push(pow(pop(), op_2));
    }
    else{
        printf("Error: %s not sopported\n", s);
    }   
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
    if (islower(input)){                // could be a command or NAME
        // get next char
        while (islower(s[++i] = input = getch())){
            ;
        }
        s[i] = '\0';
        //put the string into the stack
        if (input != EOF){
            ungetch(input);
        }
        // if is not command
        if (strlen(s) > 1){
            return NAME;
        }
        //its command
        else{
            return input;
        }   
    }
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