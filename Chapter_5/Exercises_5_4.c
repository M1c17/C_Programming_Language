#include <stdio.h>

/*Write the function strend(s,t), which returns 1 if the string
t occurs at the end of the string s, and zero otherwise */

int strend(char *s, char *t);

int main(){

    char s[100] = "hello, gworld!";
    char t[] = " world!";

    int res;

    res = strend(s,t);
    if (res == 1){
        printf("String t is at the end of s\n");
    } 
    else{
        printf("String t not at the end of s\n");
    }

}

int strend(char *s, char *t){

    char *bt = t;
    char *bs = s;

    //search for end of s
    while((*s++) != '\0'){
        ;
    }
    while ((*t++) != '\0'){
        ;
    }
    while (*s-- == *t--){
        if (t == bt || s == bs){
            break;
        }
    }
    if (*s == *t && t == bt && *s != '\0'){
        return 1;
    }    
    else{
        return 0;
    }  
}