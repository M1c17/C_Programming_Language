#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int maxline);
void unscape(char s1[], char s2[]);

int main(){

    char s1[MAXLINE];
    char s2[MAXLINE];

    get_line(s1, MAXLINE);
    printf("original line: %s\n", s1);
    unscape(s1, s2);
    printf("modify line: %s\n", s2);

}


void unscape(char s1[], char s2[]){
    int i, j;

    for (i = j = 0; s1[i] != '\0'; ++i){
        if (s1[i] != '\\'){
            s2[j++] = s1[i];
        }
        else{
            switch (s1[++i]){
        case 't':
            s2[j++] = '\t';
            break;
        case 'n':
            s2[j++] = '\n';
        default:
            s2[j] = '\\';
            s2[j] = s1[i];
            break;
            }
        }  
    }
    s2[j] = '\0';
}

int get_line(char s[], int maxline){
    int input, i;

    for (i = 0; i < maxline - 1 && (input = getchar()) != EOF; ++i){
        s[i] = input;
    }
    s[i] = '\0';
    return i;
}