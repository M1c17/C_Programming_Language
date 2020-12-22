#include <stdio.h>

void in_comment(void);
void search_syntax(int input);
void in_quote(int input);

int brackets, braces, parentheses;

int main(){

    int input;
    extern int brackets, braces, parentheses;

    //conditions
    while ((input = getchar()) != EOF){
        if(input == '/'){
            if(input == '*'){
                in_comment();
            }
            else{
                search_syntax(input);
            }
        }
        else if(input == '\'' || input == '"'){
            in_quote(input);
        }
        else{
            search_syntax(input);
        }       
    } 
    //print Errors
    if(parentheses){
        printf("Unbalance parentheses\n");
    }
    if(braces){
        printf("Unbalance braces\n");
    }
    if(brackets){
        printf("Unbalance brackets\n");
    }
}

void in_comment(void){
    int current = getchar();
    int temp = getchar();
                                                    //search end of comment
    while(current != '*' && temp != '/'){           //dismiss everything inside the comment 
        current = temp;                             //next
        temp = getchar();
    }
}


void search_syntax(int input){
    extern int braces;
    extern int brackets;
    extern int parenthesis;

        if (input == '('){
            ++parentheses;
        }
        else if(input == ')'){
            --parentheses;
        }
        if (input == '['){
            ++brackets;
        }
        else if(input == ']'){
            --brackets;
        }
        if (input == '{'){
            ++braces;
        }
        else if(input == '}'){
            --braces;
        }
}

void in_quote(int input){

    int temp = getchar();

    while(temp != input){           //search end of quote
        if(temp == '\\'){           
            getchar();              //ignore escape seq
        }
    }
}