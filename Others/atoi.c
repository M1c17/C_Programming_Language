#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int atoi(char line[]);

int main(){
    int val;
    char str[10];

    strcpy(str, "93284927");
    val = atoi(str);
    printf("String value = %s, Int value = %d\n", str, val);

    strcpy(str, "hello");
    val = atoi(str);
    printf("String value = %s, Int value = %d\n", str, val);

    return 0;
}

/* atoi: convert s to integer */
int atoi(char line[]){

    int i, n;

    for (i = 0; line[i] >= '0' && line[i] <= '9'; ++i){
        n = 10 * n + (line[i] - '0');
    }
    return n;
}
