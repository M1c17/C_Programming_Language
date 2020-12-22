#include <stdio.h>

int str_cmp(char *s, char *t);

int main(){

    char *s = "abcd";
    char *t = "abz";

    // Using strcmp() 
    int res = str_cmp(s, t); 
      
    if (res == 0) 
        printf("Strings are equal"); 
    else 
        printf("Strings are unequal"); 
      
    printf("\nValue returned by strcmp() is:  %d\n" , res); 
    return 0;

}

/*strcmp: return <0 if s < t, 0 if s == t, >0 if s>t */
int str_cmp(char *s, char *t){
    int i;

    for (i = 0; s[i] == t[i]; i++){
        if (s[i] == '\0'){
            return 0;
        }
    }
    return s[i] - t[i];
}