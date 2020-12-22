#include <stdio.h>

/*Suppose that there will never be more than one character of pushback.
Modify getch and ungetch accordingly. */

int getch(void);
void ungetch(int input);

int main(){

    char input = getch();
    printf("%c\n", input);
    ungetch(input);
    printf("ungetch called \n");
    printf("%c\n", input = getch());

    return 0;

}

int buffer = 0;

int getch(void){
    int input;

    if (buffer != 0){
        //the first char of the string
        input = buffer;          
    }
    else{
        //its zero, get next
        input = getchar();
    }
    //reset to zero
    buffer = 0;
    return input;
}
void ungetch(int input){
    //check if buffer is empty before it push a character back 
    if (buffer != 0){
        printf("Error: There are too many characters\n");
    }
    else{
        buffer = input;
    }
}
