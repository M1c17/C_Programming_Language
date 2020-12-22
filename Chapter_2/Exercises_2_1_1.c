#include <stdio.h>


/* print maximun, minimum limits of char, int,short and long variables     */

/*The logic used is:

*(<type>) => casting to the requered type
*(unsigned <type>) => casting with unsigned
* ~0 => turn all the bits to 1s
* >> 1 => right shift 1 bit to remove the sign bit

*/

int main(){

    printf("Ranges of various floating-point types from standar headers:\n");

    //signed values
    printf("Minimun Signed Char %d\n", -(char)((unsigned char)~0 >> 1)-1);
    printf("Maximun Signed Char %d\n", (char)((unsigned char )~0 >> 1));

    printf("Minimun Signed Short %d\n", -(short)((unsigned short)~0 >> 1)-1);
    printf("Maximun Sgned Short %d\n", (short)((unsigned short)~0 >> 1));

    printf("Minimun Signed Int %d\n", -(int)((unsigned int)~0 >> 1)-1);
    printf("Maximun Signed Int %d\n", (int)((unsigned int)~0 >> 1));

    printf("Minimun Signed Long %ld\n", -(long)((unsigned long)~0 >> 1)-1);
    printf("Maximum Signed Long %ld\n", (long)(unsigned long)~0 >>1);

    //unsigned values
    printf("Maximum Unsigned Char %d\n", (unsigned char)~0);
    printf("Maximum Unsigned Int %d\n", (unsigned int)~0);
    printf("Maximum Unsigned Short %u\n", (unsigned short)~0);
    printf("Maximum Unsigned Long %ld\n", (unsigned long)~0);
    return 0;
}