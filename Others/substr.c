#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* substr(char* src, int start, int len);

int main(){
    char* test = malloc(sizeof(char)*5); // the reason I don't use char* = "test"; is because I wouldn't be able to use free() on it then
    strcpy(test, "test");
    char* sub = substr(test, 1, 2); // save the substr in a new char*
    free(test); // just wanted the substr from test
    printf("%s\n", sub); // prints "es"

    // ... free when done with sub
    free(sub);
}

char* substr(char* src, int start, int len){
    char* sub = malloc(sizeof(char)*(len+1));
    memcpy(sub, &src[start], len);
    sub[len] = '\0';
    return sub;
}