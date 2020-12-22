#include <stdio.h>
#define BUFSIZE 1000

/* Our getch and ungetch do not handle a pushed back EOF
correctly. Decide what their properties ought to be if an EOF
is push back then implement your design */

int getch(void);
void ungetch(int f);

int main(){

    int input = getch();
    printf("input: %s", input);
    ungetch(input);

}

int buf_pos = 0;
int buffer[BUFSIZE];

int getch(void){
    return (buf_pos > 0) ? buffer[buf_pos--] : getchar();
}
void ungetch(int f){
    if (buf_pos > = BUFSIZE){
        printf("There are no space in buffer\n");
    }
    else{
        buffer[buf_pos++] = f;
    }
}

/* if were are going to treat EOF (-1) as any other char buffer should
declared as an array of integer.
No conversion will occur and EOF (-1) or any negative number will be handled
in a portable way */
