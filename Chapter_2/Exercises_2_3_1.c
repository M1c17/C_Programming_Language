#include <stdio.h>


/* Write the function htoi(s), which converts a string of hexadecimal
digits into its equivalent integer value.
the allowable digits are 0 through 9 and A through F. */

#define MAXLINE 1000
#define YES 1
#define NO 0

int get_line(char hex[], int maxline);
int htoi(char hex[]);

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

/*Convert hexadecimal string s to decimal*/
int htoi(char hex[]){
    int hexdigit, i, inhex, n;
    i = 0;

    if (hex[i] == '0'){
        ++i;
        if(hex[i] == 'x'|| hex[i] == 'X'){
            ++i;      
        }
    }
    n = 0;                      //integer value to be returned
    inhex = YES;                //flag => assume valid hex value
    for ( ; inhex == YES; ++i){
        if (hex[i] >= '0' && hex[i] <= '9'){
            hexdigit = hex[i] -'0';
        }
        else if(hex[i] >= 'a' && hex[i] <= 'f'){
            hexdigit = hex[i] -'a' + 10;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F'){
            hexdigit = hex[i] -'A' + 10;
        }
        else{
            inhex = NO;
            printf("Error: Invalid value.\n");
        }
        if(inhex == YES){
            n = 16 * n + hexdigit;
        }
    }
    return n;
}
