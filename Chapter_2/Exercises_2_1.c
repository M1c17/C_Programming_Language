#include <stdio.h>
#include <limits.h>

/* Write a program to determine the ranges of char, short, int,
and long variables, both signed and unsigned, by printing appropiate
values from standard headers and by direct computation. Harder if you
compute them: determine the ranges of the various floating-point types.*/

/* print maximun, minimum limits of char, int,short and long variables     */


int main(){

    printf("Ranges of various floating-point types from standar headers:\n");

    //signed values
    printf("Minimun Signed Char %d\n", SCHAR_MIN);
    printf("Maximun Signed Char %d\n", SCHAR_MAX);

    printf("Minimun Signed Short %d\n", SHRT_MIN);
    printf("Maximun Sgned Short %d\n", SHRT_MAX);

    printf("Minimun Signed Int %d\n", INT_MIN);
    printf("Maximun Signed Int %d\n", INT_MAX);

    printf("Minimun Signed Long %ld\n", LONG_MIN);
    printf("Maximum Signed Long %ld\n", LONG_MAX);

    //unsigned values
    printf("Maximum Unsigned Char %d\n", UCHAR_MAX);
    printf("Maximum Unsigned Int %d\n", UINT_MAX);
    printf("Maximum Unsigned Short %u\n", USHRT_MAX);
    printf("Maximum Unsigned Long %ld\n", ULONG_MAX);
    return 0;
}