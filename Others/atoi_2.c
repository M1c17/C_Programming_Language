#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* atoi: convert s to integer; version 2 */

int atoi(char line[]);

int main(){
    int val;
    char str[10];

    strcpy(str, "-93284927");
    val = atoi(str);
    printf("String value = %s, Int value = %d\n", str, val);

    strcpy(str, "hello");
    val = atoi(str);
    printf("String value = %s, Int value = %d\n", str, val);

    return 0;
}

int atoi(char line[]){
    //Initialize variables
    int i, n, sign;
    //skip white space, if any
    for (i = 0; isspace(line[i]); ++i){
        ;
    }
    //get sign, if any
    sign = (line[i] == '-') ? -1 : 1;
    //skip sign, if any 
    if (line[i] == '+' || line[i] == '-'){
        ++i;
    }
    //get integer part and convert it
    for (n = 0; isdigit(line[i]); ++i){
        n = 10 * n + (line[i] - '0');
    }
    return sign * n;
}

