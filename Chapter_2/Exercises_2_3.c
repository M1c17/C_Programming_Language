#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Write the function htoi(s), which converts a string of hexadecimal
digits into its equivalent integer value.
the allowable digits are 0 through 9 and A through F. */

#define MAXLINE 1000

int get_line(char hex[], int maxline);
int htoi(char hex[]);
int get_hexValue(char c);

int main(){

    char hex[MAXLINE];

    printf("Please, Enter a string integer: \n");
    get_line(hex, MAXLINE);
    printf("hex value: %d\n", htoi(hex));
}

int get_line(char hex[], int maxline){
    int input, i;

    for (i = 0; i < maxline - 1 && (input = getchar()) != EOF && input != '\n'; ++i){
        hex[i] = input;
    }
    hex[i] = '\0';
    return i;
}

/*Convert string to hexadecimal */
int htoi(char hex[]){
    int i;
    int len = strlen(hex);
    int power = 1;
    int dec = 0;

    for(i = 0; i < len - 1; ++i){
        if (hex[i] == '0' && (hex[i + 1] == 'x' || hex[i + 1] == 'X')){
            i +=2;
        }
        if((hex[i] >= '0' && hex[i] <= '9') || (hex[i] >= 'a' && hex[i] <= 'f') || (hex[i] >= 'A' && hex[i] <= 'F')){
            dec += get_hexValue(hex[i]) * power;
            power *= 16;
        }
        else{
            printf("Error: Invalid hexadecimal value\n");
        }
    }
    return dec;
}

int get_hexValue(char c){
    if(isalpha(c)){
        return toupper(c) - 'A' + 10;
    }
    return c - '0';
}