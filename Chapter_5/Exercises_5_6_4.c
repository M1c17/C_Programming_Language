#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

/* atof: convert string s to double; pointer version */

double atof(char *s);

int main() {

    char s[MAXLINE] = "-96986";
    printf("atof line: %g\n", atof(s));

}

double atof(char *s){
    int sign;
    double n, power;

    for ( ;isspace(*s); s++){
        ;
    }
    sign = (*s == '-')? -1 : 1;
    if (*s == '-' || *s == '+'){
        s++;
    }

    for (n = 0; isdigit(*s); s++){
        n = 10 * n + (*s - '0');
    }

    if (*s == '.'){
        s++;
    }

    for (power = 1.0 ; isdigit(*s); s++){
        n =  10.0 * n + (*s - '0');
        power *= 10.0;
    }
    return sign * n / power;
}
