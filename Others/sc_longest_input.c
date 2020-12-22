#include <stdio.h>

#define MAXLINE 1000

/*write function longest_string but with line, longest and max
as external variables */

//Initialize external variables
int max;
char longest[MAXLINE];           /* longest line saved */
char line[MAXLINE];              /* current input line */


int get_line(void);
void copy(void);

//test get_line and copy to get the longest input
int main(){
    extern int max;
    extern char longest[];
    int len;

    while ((len = get_line()) > 0){
        if (len > max){
            max = len;
            copy();
        }
    }
    if(max > 0){
        printf("The longest input: \n%s", longest);
    }
    return 0;
}

//get input return lenght of str
int get_line(void){
    int input, i;
    extern char line[];

    for(i = 0; i < MAXLINE - 1 && (input = getchar()) != EOF && input != '\n'; ++i ){
        line[i] = input;
    }
    if(input == '\n'){
        line[i] = input;
        ++i;
    }
    line[i] = '\0';
    return i;
}
//copy string and keep track of longest string
void copy(void){
    extern char line[];
    extern char longest[];

    int i = 0;
    while ((longest[i] = line[i]) != '\0'){
        ++i;
    }
}




