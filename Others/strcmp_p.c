#include <stdio.h>

/* strcmp(s,t) : return int
if s < ASCII return negative
else if(==) return 0
else return positive */

int str_cmp(char *s, char *t);
int main(){

    char *s = "abcd";
    char *t = "abz";
    int res;

    res = str_cmp(s, t);

    if (res == 0){
        printf("String are equal\n");
    } else{
        printf("String are inequal\n");
    }

    printf("String cmp result: %d\n", res);

}

/*strcmp: return <0 if s < t, 0 if s == t, >0 if s>t */
int str_cmp(char *s, char *t){

    for ( ; *s == *t; s++, t++){
        if (*s == '\0'){
            return 0;
        }
    }
    return *s - *t;   
}
