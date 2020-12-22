#include <stdio.h>
#include <stdarg.h>             // contains a set of macro definitions that define how to step through an argument list
#include <ctype.h>

#define LOCALFMT 100

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

    minprintf("Integers: %d, %i\n", 1, 2);
    minprintf("Unsigned: %u\n", ~0);
    minprintf("Float: %f\n", 1.23456789);
    minprintf("String: %s\n", "Hello World!");
    minprintf("Octal: %o\n", 63);
    minprintf("Hexadecimal: %x\n", 255);
    minprintf("Hexadecimal: %X\n", 255);
    minprintf("Char (newline): %c\n", '\n');
    minprintf("Exponential: %e\n", 300e6);
    minprintf("Exponential: %E\n", 6626e-37);
    minprintf("%%g: %g\n", 300000000.);
    minprintf("%%G: %G\n", 0.000005);
    minprintf("Percentage symbol: %%\n");

    minprintf("Preceding with zeros: %010d \n", 1997);
    minprintf("Preceding with empty spaces: %10d \n", 1997);
    minprintf("Integers: %i %u \n", -3456, 3456);
    minprintf("Some different radices: %d %x %o \n", 100, 100, 100);
    
    return 0;
}

/*
How minprintf walks along the arguments list when the list
doesn't even have a name 
*/
void minprintf(char *fmt, ...){
    va_list ap;
    char *p, *sval;
    char localfmt[LOCALFMT];
    int ival, i;
    unsigned uval;
    double dval;

    va_start(ap, fmt);              //make ap point to 1st unnamed arg
    for (p = fmt; *p; p++){
        if (*p != '%'){
            putchar(*p);
            continue;
        }
        i = 0;
        localfmt[i++] = '%';
        // i.e %03o || %10s || %4.0f
        while (*(p+1) && !isalpha(*(p+1))){
            localfmt[i++] = *++p;
        }
        localfmt[i++] = *(p+1);
        localfmt[i] = '\0';
        
        switch (*++p)
        {
        case 'd':
        case 'i':
        case 'c':
            ival = va_arg(ap, int);
            printf(localfmt, ival);
            break;

        case 'u':
            uval = va_arg(ap, unsigned);
            printf(localfmt, uval);
        break;

        case 'x':
        case 'X':
        case 'o':
        case 'O':
            ival = va_arg(ap, unsigned);
            printf(localfmt, ival);
        break;

        case 'f':
        case 'g':
        case 'G':
        case 'e':
        case 'E':
            dval = va_arg(ap, double);
            printf(localfmt, dval);
        break;

        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++){
                putchar(*sval);
            }
            break;

        default:
            printf("%s", localfmt+1);
            break;
        }
    }
    va_end(ap);         // clean up when done
}