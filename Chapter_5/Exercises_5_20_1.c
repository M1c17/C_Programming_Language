#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
Expand dcl to handle declarations with funcitons arguments
types, qualifiers like const, and so on
*/

#define MAXTOKEN 100
#define BUFSIZE 1000

void dcl(void);
void dirdcl(void);
int gettoken(void);
void error(char *);

void dclspec(void);
int typespec(void);
int typequal(void);
int compare( const void *, const void *);
void parmdcl(void);

enum { PARENS, BRACKETS, NAME };
enum { NO, YES };

int tokentype;
char token[MAXTOKEN];
char datatype[MAXTOKEN];
char name[MAXTOKEN];
char out[1000];
int prevtoken;

int main(){

    while (gettoken() != EOF){
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        if (tokentype != '\n'){
            printf("Syntax error: %c", tokentype);
        }
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

void dcl(void){
    int n_asterk;

    for (n_asterk = 0; gettoken() == '*'; ){
        n_asterk++;
    }
    dirdcl();
    // print
    while (n_asterk-- > 0){
        strcat(out, " pointer to");
    }
}

void dirdcl(void){
    int type;

    if (tokentype == '('){
        dcl();
        if (tokentype != ')'){
            error("Error: missing )");
            prevtoken = YES;
        }
    }else if(tokentype == NAME){
        strcpy(name, token);
        // if (name[0] == '\0'){
        //     strcpy(name, token);
        // }
    }else{
        prevtoken = YES;
    }
    // print
    while ((type = gettoken()) == PARENS || type == BRACKETS || type == '('){
        if(type == PARENS){
            strcat(out, " function returning");
        }
        else if(type == '('){
            strcat(out, " function expecting");
            parmdcl();
            strcat(out, " and returning");
        }
        else{
            strcat(out, " array ");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

int buf_pos = 0;
int buffer[BUFSIZE];

int getch(void){
    return (buf_pos > 0)? buffer[--buf_pos] : getchar();
}

void ungetch(int c){
    if (buf_pos >= BUFSIZE){
        error("Error: There are too many element in buffer");
    }
    else{
        buffer[buf_pos++] = c;
    }
}

int gettoken(void){
    int input;
    char *p = token;

    if (prevtoken == YES){
        prevtoken = NO;
        return tokentype;
    }

    // skips blanks
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
        for (*p++ = input; (*p++ = getch()) != ']'; ){
            ;
        }
        *p++ = '\0';
        return tokentype = BRACKETS;
    }
    else if(isalpha(input)){
        for (*p++ = '['; isalnum(input = getch()); ){
            *p++ = input;
        }
        *p = '\0';
        ungetch(input);
        return tokentype = NAME;
    }
    else{
        return tokentype = input;
    }
}

void error(char *error_msg){
    printf("%s\n", error_msg);
    prevtoken = YES;
}

/*typespec: return YES if token is a type-specifier */
int typespec(void){
    char *pt = token;
    static char *types[] = {
        "char",
        "int",
        "void"
    };
    int n_elements = sizeof(types)/sizeof(char *);
    int *found;
    found = (int *) bsearch(&pt, types, n_elements, sizeof(char *), compare);

    if (found != NULL){
        return YES;
    }
    else{
        return NO;
    }
}

/* typequal: return YES if token is a type-qualifier */
int typequal(void){

    static char *typeq[] = {
        "const",
        "volatile"
    };
    char *pt = token;
    int n_elements = sizeof(typeq)/sizeof(char *);
    int *found;
    found = (int *) bsearch(&pt, typeq, n_elements, sizeof(char *), compare);

    if( found != NULL){
        return YES;
    }
    else{
        return NO;
    }
}

/* compare: compare two strings for bsearch */
int compare( const void *op1, const void *op2 )
  {
    const char **p1 = (const char **) op1;
    const char **p2 = (const char **) op2;
    return( strcmp( *p1, *p2 ) );
  }

/* dclspec: declaration specification */
void dclspec(void){

    char temp[MAXTOKEN];

    temp[0] = '\0';
    gettoken();
    do
    {
        if (tokentype != NAME){
            prevtoken = YES;
            dcl();
        }
        // print type-specifier
        else if(typespec() == YES){
            strcat(temp, " ");
            strcat(temp, token);
            gettoken();
        }
        //print type-qualifier
        else if(typequal() == YES){
            strcat(temp, " ");
            strcat(temp, token);
            gettoken();
        }else{
            prevtoken = YES;
            error("Unknown type in parameter list");
        }
    } while (tokentype != ',' && tokentype != ')');
    strcat(out, temp);
    if (tokentype == ','){
        strcat(out, ",");
    }  
}

/* parmdcl: parse a parameter declarator */
void parmdcl(void){
    do
    {
        dclspec();
        
    } while (tokentype == ',');
    if (tokentype != ')'){
        error("Error: missing ) in parameter declaration");
    }
}