#include <stdio.h>
#include <stdarg.h>             // contains a set of macro definitions that define how to step through an argument list

/*
minprintf: minimal printf with variable argument list */

// va_list = declare a variable that will refers each arg in turn
// here will call this variable ap = "argument pointer"
// va_start = initializes ap to point to the first unnamed argument
// va_start = call before ap is used
// va_arg = returns one argument and step ap to the next one
// va_arg = uses a type name to determine what type to return how big a step to take
// va_end = cleanup // called before function returns.

void minprintf(char *fmt, ...);

int main(){
    char *s = "hello, world";
    minprintf("%s\n", s);
    int c = 6;
    minprintf("%d\n", c);
    double c1 = 6.2;
    minprintf("%f\n", c1);
    //default
    minprintf("me again\n");
    char *s1 = "hello, world2";
    minprintf("%s", s1);

}

/*
How minprintf walks along the arguments list when the list
doesn't even have a name 
*/
void minprintf(char *fmt, ...){
    va_list ap;
    char *p, *sval;
    int intval;
    double dval;

    va_start(ap, fmt);              //make ap point to 1st unnamed arg
    for (p = fmt; *p; p++){
        if (*p != '%'){
            putchar(*p);
            continue;
        }
        switch (*++p){
        case 'd':
            intval = va_arg(ap, int);
            printf("%d", intval);
            break;
        case 'f':
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++){
                putchar(*sval);
            }
            break;

        default:
            putchar(*p);
            break;
        }
    }
    va_end(ap);         // clean up when done
}