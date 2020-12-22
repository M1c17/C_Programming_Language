#include <stdio.h>

/* strindex: return index of t in s, -1 if none. pointer version */

int strindex(char *, char *);

int main(){
    char s[100] = "could be posible";
    char t[100] = "ould";
    int res = strindex(s, t);
    int found;

    if (res == -1){
        printf("didn't found line\n");
    }
    else{
        printf("found line: %s\n", s);
        found++;
    }

}

int strindex(char *s , char *t){

    char *b = s;
    char *p, *r;

    for ( ; *s != '\0' ; s++){
        for(p = s, r = t; *r != '\0' && *p == *r; p++, r++){
            ;
        }
        if (r > t && *r == '\0'){
            return s - b;
        }
    }
    return -1;
}