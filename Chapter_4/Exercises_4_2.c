#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

/* Extend atof to handle scientific notation of the form 123.456e-6
where a floating point number may be followed by e or E and an optionally
signed exponent */

double atof(char s[]);
int get_line(char s[], int maxline);

int main(){

    char s[MAXLINE];
    get_line(s, MAXLINE);
    printf("double int: %f\n", atof(s));

    return 0;
}

int get_line(char s[], int maxline){
    int input, i;

    for (i = 0; i < maxline - 1 &&  (input = getchar()) != EOF && input != '\n'; ++i){
        s[i] = input;
    }
    if(input == '\n'){
        s[i] = input;
    }
    s[i] = '\0';
    return i;
}

/*Convert string to double */
double atof(char s[]){
    //Initialize variables
    double power, val;
    int exp, sign, i;
    //skip white space
    for (i = 0; isspace(s[i]); ++i){
        ;
    }
    //put sign
    sign = (s[i] == '-') ? -1 : 1;
    //walk through sign
    if (s[i] == '-' || s[i] == '+'){
        ++i;
    }
    //convert digit to string
    for (val = 0.0; isdigit(s[i]); ++i){
        val = 10.0 * val + (s[i] - '0');
    }
    //walk through  point char .
    if (s[i] == '.'){
        ++i;
    }
    //calculate power to string 
    for (power = 1.0; isdigit(s[i]); ++i){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    //handle scientific notation of the form 123.456e-6
    if (s[i] == 'e' || s[i] == 'E'){
        sign = (s[i++] == '-') ? -1 : 1;
        if (s[i] == '-' || s[i] == '+'){
            ++i;
        }
        for (exp = 0; isdigit(s[i]); ++i){
            exp = 10 * exp + (s[i] - '0');
        }
        if (sign == 1){             //positive exponent
            while (exp > 0){
                //printf("%s\n", "hello");
                power *= 10;
                --exp;
            }
        }
        else{                       //negative exponent
            while (exp > 0){
                power /= 10;
                --exp;
            }
        }
    }
    return sign * val / power;;
}