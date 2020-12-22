#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

/*function strindex => return the postion or index in the string s where
the string t begins  or -1 is s doesnt contain t*/

int get_line(char s[], int maxline);
int strindex(char s[], char pattern[]);

int main(){

    char s[MAXLINE];
    char pattern[MAXLINE] = "ould";
    int found;

    while(get_line(s, MAXLINE) > 0){
        if(strindex(s, pattern) >= 0){
            printf("%s", s);
            found++;
        }    
    }
    return found;
}

int get_line(char s[], int maxline){
    int input, i;

    i = 0;

    while (--maxline > 0 && (input = getchar()) != EOF && input != '\n'){
        s[i++] = input;
    }
    if(input == '\n'){
        s[i++] = input;
    }
    s[i] = '\0';
    return i;
}

int strindex(char s[], char pattern[]){
    int i, j, k;

    //for(i = 0; s[i] != '\0'; ++i){ OR
    for(i = strlen(s) - strlen(pattern); i >= 0; --i){    
        for(j = i, k = 0; pattern[k] != '\0' && s[j] == pattern[k]; ++j, ++k){
            ;
        }
        if (k > 0 && pattern[k] == '\0'){
            //printf("%d\n", i);
            return i;
        }
    }
    return -1;
}