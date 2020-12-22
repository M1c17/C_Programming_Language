#include <stdio.h>

/*Write a function escape(s,t) => converts character like tab and 
new line in \t, \n (visible escape sequences).
copies the string t to s. Use switch.
Write a function for the other direction as well converting escape
sequences into the real characters;

*/

#define MAXLINE 1000

int get_line(char to[], int maxline);
void escape(char to[], char from[]);

int main(){

    char to[MAXLINE];
    char from[MAXLINE];
    
    get_line(from, MAXLINE);
    printf("original line: \n%s\n", from);
    escape(to, from);
    printf("escape line: \n%s\n", to);
}

int get_line(char from[], int maxline){
    int input,i;

    for(i = 0; i < maxline && (input = getchar()) != EOF; ++i){
        from[i] = input;
    }
    from[i] = '\0';
    return i;
}

void escape(char to[], char from[]){
    int i, j;

    for(i = j = 0; from[i] != '\0'; ++i){
        switch (from[i])
        {
        case '\n':
            to[j++] = '\\';
            to[j++] = 'n';
            i++;
            break;
        case '\t':
            to[j++] = '\\';
            to[j++] = 't';
            i++;
        default:
            to[j++] = from[i];
            break;
        }
    }
    to[j] = '\0';
}