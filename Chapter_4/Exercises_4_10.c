#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXOP 100
#define MAXLINE 1000
#define MAXSTACK 100
#define NUMBER '0'

int get_line(char s[], int maxline);
int get_op(char s[]);
void push(int f);
double pop(void);

int main(){

    char s[MAXLINE];
    int type;
    double op_2;
    
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
                printf("Zero division error");
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

int get_line(char s[], int maxline){
    int input, i;

    for (i = 0; i < maxline -1 && (input = getchar()) != EOF && input != '\n'; ++i){
        s[i] = input;
    }
    if (input == '\n'){
        s[i] = input;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int s_p = 0;
int stack[MAXSTACK];

void push(int f){
    if(s_p < MAXSTACK){
        stack[s_p++] = f;
    }
    else{
        printf("Error: cannot push element, stack is full\n");
    }
}

double pop(void){
    if (s_p > 0){
        return stack[--s_p];
    }
    else{
        printf("Error: The stack is empty.\n");
        return 0.0;
    }
}

char line[MAXLINE];
int idx_line = 0;  

int get_op(char s[]){
    int input, i;
    
    if (line[idx_line] == '\0'){
        if (get_line(line, MAXLINE) == 0){
            return EOF;
        }
        else{
            idx_line = 0;
        }
    }
    //skip blanks
    while((s[0] = input = line[idx_line++]) == ' ' || input == '\t'){
        ;
    }
    s[1] = '\0';
    if (!isdigit(input) && input != '.'){
        return input;
    }
    i = 0;
    if (isdigit(input)){
        while (isdigit(s[++i] = input = line[idx_line++])){
            ;
        }
    }
    if (input == '.'){
        while(isdigit(s[++i] = input = line[idx_line++])){
            ;
        }
    }
    //s[i] = '\0';
    //we went one char to far
    idx_line--;
    return NUMBER;   
}


