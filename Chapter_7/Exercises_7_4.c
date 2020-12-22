#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>

#define LOCALFMT 100

/*
Write a private version of scanf analogous to mindprintf from the previous section
*/

void minscanf(char *frmt, ...);

int main(){
    
    unsigned int u;
    int i1, i2;
    float f1, f2;
    double d;
    char c;
    char s[100];

    printf("Enter two integer: \n");
    minscanf("%d %i", &i1, &i2);
    printf("Integer: %d, %i\n", i1, i2);

    printf("Enter an unsigned integer: \n");
    minscanf("%u", &u);
    printf("Unsigned: %u\n", u);

    printf("Enter two floating integer: \n");
    minscanf("%f %f", &f1, &f2);
    printf("Float: %f %f\n", f1, f2);

    // A string is read until the next \n
    printf("Enter a string: \n");
    minscanf("%s", &s);
    printf("String: %s\n", s);

    printf("Enter a octal number: \n");
    minscanf("%o", &i1);
    printf("octal: %d\n", i1);

    printf("Enter a hexadecimal number: \n");
    minscanf("%x", &i1);
    printf("hexadecimal: %d\n", i1);

    printf("Enter a character: ");
    minscanf("%c", &c);
    printf("New line consume\n");
    minscanf("%c", &c);
    printf("Char: %c\n", c);

    printf("Enter two Exponential: \n");
    minscanf("%e %E", &f1, &f2);
    printf("Exponentials: %e, %E\n", f1, f2);

    printf("Enter two Exponential: \n");
    minscanf("%g %G", &f1, &f2);
    printf("Exponentials: %g, %G\n", f1, f2);

    return 0;
}

/*minscanf: with variables arguments list */
void minscanf(char *frmt, ...){

    va_list ap;
    char *p, *sval, *cval;
    int i;
    int *ival;
    float *fval;
    unsigned *uval;
    char localfrmt[LOCALFMT];

    i = 0;
    va_start(ap, frmt);
    for (p = frmt; *p; p++){
        if (*p != '%'){
            localfrmt[i++] = *p;
            putchar(*p);
            continue;
        }
        localfrmt[i++] = '%';
        while (*(p+1) && !isalpha(*(p+1))){
            localfrmt[i++] = *++p;
        }
        localfrmt[i++] = *(p+1);
        localfrmt[i] = '\0';

        switch (*++p)
        {
        case 'd':
        case 'i':
            ival = va_arg(ap, int*);
            scanf(localfrmt, ival);
            break;
        case 'u':
        case 'x':
        case 'X':
        case 'o':
        case 'O':
            uval = va_arg(ap, unsigned*);
            scanf(localfrmt, uval);
            break;
        case 'f':
        case 'g':
        case 'G':
        case 'e':
        case 'E':
            fval = va_arg(ap, float*);
            scanf(localfrmt, fval);
            break;
        
        case 's':
        case 'c':
            sval = va_arg(ap, char*);
            scanf(localfrmt, sval);
            break;
        default:
            scanf("%s", localfrmt);
            break;
        }
        i = 0;          //reset
    }
    va_end(ap);
}