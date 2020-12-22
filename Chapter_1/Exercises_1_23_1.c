#include <stdio.h>

void remove_comment(int current);
void in_comment(void);
void echo_quote(int c);

//everytime you call getchar it will give u the next char 

int main(){
    int current, temp;

    while ((current = getchar()) != EOF){
        remove_comment(current);
    }
    return 0;
}

void remove_comment(int current){
    int temp;

    if(current == '/'){
        if ((temp = getchar()) == '*'){         //beginning of comment
            in_comment();
        }
        else if (temp == '/'){                  
            putchar(current);
            remove_comment(temp);
        }
        else{
            putchar(current);
            putchar(temp);
        }
    }
    else if (current == '\'' || current == '"'){
        echo_quote(current);
    }
    else{
        putchar(current);
    }
}
void in_comment(void){
    int current, temp;

    current = getchar();
    temp = getchar();
    while (current != '*' || temp != '/'){          //search for end of comment 
        current = temp;
        temp = getchar();       // next char
    }

}
//ensure that anything between quotes and not mistake for a comment
void echo_quote(int current){
    int temp;

    putchar(current);
    while ((temp = getchar()) != current){
        putchar(temp);
        if (temp == '\\'){
            putchar(getchar());         //ignore scape seq
        }
    }
    putchar(temp);
}