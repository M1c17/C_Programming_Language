#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSTACK 100
#define MAXOP 100       //  max size of operand or operator 
#define NUMBER '0'      // signal that a number was found (FLAG)
#define BUFSIZE 100

int getop(char s[]);
void push(double f);
double pop(void);

int main(){

    char s[MAXOP];
    int type;
    double temp;

    while ((type = getop(s)) != EOF){
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());        //+ is commutative
            break;
        case '*':
            push(pop() * pop());        //* is commutative 
            break;
        case '-':                       //- is not commutative
            temp = pop();
            push(pop() - temp);
            break;
        case '/':                       // / is not commutative 
            temp = pop();
            if(temp != 0.0){
                push(pop() / temp);
            }
            else{
                printf("Zero division Error");
            }   
            break;
        case '\n':                      //result
            printf("result = %.8g\n", pop());
            break;
    
        default:
            printf("Error: unknow command %s\n", s);
            break;
        }
    }
    return 0;
}

int s_pos = 0;
double stack[MAXSTACK];

/* push: push f onto value stack */
void push(double f){
    if (s_pos < MAXSTACK){
        stack[s_pos++] = f;
    }
    else{
        printf("Error: stack full, can't push %g\n", f);
    }
}

/* pop: pop f onto value stack */
double pop(void){
    if (s_pos > 0){
        return stack[--s_pos];

    }
    else{
        printf("Error: the stack is empty\n");
        return 0.0;
    }
}

char buffer[BUFSIZE];
int buf_pos = 0;

/* return the last character of the buffer*/
int getch(void){
//if there still exist characters in the buffer return the last one
//else called getchar()
    return (buf_pos > 0) ? buffer[--buf_pos] : getchar();
}

/* push back the last character into the buffer */
void ungetch(int input){
    if (buf_pos >= BUFSIZE){
        printf("ungetch: too many characters\n");
    }
    else{
        buffer[buf_pos++] = input;
    }

}

/*get next operator or numeric operand */
int getop(char s[]){

    int i, input;
    i = 0;

    //skip blanks and tabs 
    while((s[0] = input = getch()) == ' ' || input == '\t'){
        ;
    }
    s[1] = '\0';
    //if the character is not a digit or a decimal point return it
    //otherwise, collect a string of digits (which might include a decimal point)
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
    if(input != EOF){
        ungetch(input);
    }
    //and return NUMBER.
    return NUMBER;
}