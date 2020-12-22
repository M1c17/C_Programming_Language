#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
Modify undcl so that it does not add redundant parentheses 
*/

#define MAXTOKEN 100
#define BUFSIZE 1000
// #define YES 1
// #define NO 0

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

void dcl(void);
void dirdcl(void);

void error(char *);
int is_valid_datatype(char *);

int gettoken(void);
int next_token(void);

int tokentype;                      // type of last token
char token[MAXTOKEN];               // last token string
char name[MAXTOKEN];                // identifier name
char datatype[MAXTOKEN];            // data type = char, int, etc.
char out[1000];                     // output string
int prevtoken = NO;

/* convert word description to declaration */
int main(){
    int type;
    char temp[MAXTOKEN];

    while (gettoken() != EOF){
        strcpy(out, token);
        while ((type = gettoken()) != '\n'){
            if (type == PARENS || type == BRACKETS){
                strcat(out, token);
                //printf("here 0: %s\n", out);
            }
            else if(type == '*'){
                if ((type = next_token()) == PARENS || type == BRACKETS){
                    sprintf(temp, "(*%s)", out);
                    //printf("here1: %s\n", out);
                }
                else{
                    sprintf(temp, "*%s", out);
                }
                strcpy(out, temp);
            }
            else if(type == NAME){
                sprintf(temp, "%s %s", token, out);
                //printf("here2: %s\n", token);
                //printf("here3: %s\n", out);
                strcpy(out, temp);
            }
            else{
                printf("Error: Invalid input at %s\n", token);
            }
        }
        printf("%s\n", out);
    }
    return 0;
}

/* dirdcl: parse a direct declarator */
void dirdcl(void){
    int type;

    if (tokentype == '('){
        dcl();
        if (tokentype != ')'){
            error("Error: missing )");
        }
    }
    else if(tokentype == NAME){
        strcpy(name, token);
    }
    else{
        error("Error: expected name or (dcl)\n");
    }
    while ((type = gettoken()) == PARENS || type == BRACKETS){
        if (type == PARENS){
            strcat(out, " function returning");
        }
        else{
            strcat(out, " array ");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

/*
dcl: parse a declarator */ 
void dcl(void){
    int ns;

    for (ns = 0; gettoken() == '*'; ){
        ns++;
    }
    dirdcl();
    while (ns-- > 0){
        strcat(out, " pointer to");
    }
}

int buf_pos = 0;
int buffer[BUFSIZE];

int getch(void){
    return (buf_pos > 0) ? buffer[--buf_pos] : getchar();
}
void ungetch(int input){
    if (buf_pos >= BUFSIZE){
        printf("There are no space in buffer\n");
    }
    else{
        buffer[buf_pos++] = input;
    }
}

/* gettoken: skips blanks and tabs, then find the next token in the input;
a "token" is a name, a pair of parentheses, a pair of brackets perhaps 
including a number, or any other single character */

/*return next token */
int gettoken(void){
    int input;
    char *p = token;

    // if there is a token available do not get a new one yet
    if (prevtoken == YES){
        prevtoken = NO;
        return tokentype;
    }

    while ((input = getch()) == ' ' || input == '\t'){
        ;
    }
    if (input == '('){
        if ((input = getch()) == ')'){
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else{
            ungetch(input);
            return tokentype = '(';
        }
    }
    else if(input == '['){

        //found brackets
        for (*p++ = input; (*p++ = getch()) != ']'; ){
            ;
        }
        *p = '\0';
        return tokentype = BRACKETS;
    //found name
    }else if(isalpha(input)){
        //found number
        for (*p++ = input ; isalnum(input = getch()); ){
            *p++ = input;
        }
        *p = '\0';
        ungetch(input);
        return tokentype = NAME;
    }
    //return ), *, others
    else{
        return tokentype = input;
    }   
}

/* nextoken : get the next token and push it back */
int next_token(void){
    int type;
    type = gettoken();
    prevtoken = YES;
    return type;
}

int is_valid_datatype(char *datatype){
    return strcmp(datatype, "char") == 0 ||
           strcmp(datatype, "int") == 0  ||
           strcmp(datatype, "void") == 0 ||
           strcmp(datatype, "short") == 0 ||
           strcmp(datatype, "long") == 0 ||
           strcmp(datatype, "float") == 0 ||
           strcmp(datatype, "double") == 0;
}

/*error: print error msg and indicate available token */
void error(char *error_line){
    printf("%s\n", error_line);
    prevtoken = YES;
}


