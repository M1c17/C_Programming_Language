#include <stdio.h>

#define MAXLINE 1000

/*Write a function for the other direction as well converting escape
sequences into the real characters; */

int get_line(char from[], int maxline);
void unescape(char from[], char to[]);

int main(){

    char to[MAXLINE];
    char from[MAXLINE];

    printf("Please, Enter input: \n");
    get_line(from, MAXLINE);
    printf("original line: %s\n", from);
    unescape(from, to);
    printf("unscape line: %s\n", to);

}

int get_line(char from[], int maxline){
    int input, i;

    for (i = 0; i < maxline - 1 && (input = getchar()) != EOF; ++i){
        from[i] = input;
    }
    from[i] = '\0';
    return i;
}

void unescape(char from[], char to[]){
    int i, j;

    for (i = j = 0; from[i] != '\0'; ++i, ++j){
        switch (from[i])
        {
        case '\\':
            switch (from[++i])
            {
            case 't':
                to[j] = '\t';
                break;
            case 'n':
                to[j] = '\n';
                break;
            default:
                to[j++] = '\\';
                to[j] = from[i];
                break;
            }
            break;
        default:
            to[j] = from[i];
            break;
        }
    }
    to[j] = '\0';
}