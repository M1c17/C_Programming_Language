# include <stdio.h>

/*Write str_ncmp(s, t, n) compares almost n elements from t to s */
int str_ncmp(char *s, char *t, int n);

int main(){

    char s[100] = "hello";
    char t[] = "hello";
    int n = 3;
    int res = str_ncmp(s, t, n);

    if (res == 0) {
        printf("Strings are equal\n");
    }   
    else {
        printf("Strings are unequal\n");
    }
}

int str_ncmp(char *s, char *t, int n){
    for (n--; (*s++ == *t++) != 0 && n > 0; n--){
        if (*s == '\0'){
            return 0;
        }       
    }
    return *s - *t;   
}
