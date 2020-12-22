#include <stdio.h>

/*Write a function rightrot(x, n) that return the value of the integer
x rotated to the right by n bit positions.


    the program above assumes that we are using 8bit ints.

    00110101 = 53 in decimal - Beginning value
    10100110 = 166 in decimal - Final result

*/

unsigned rightrot (unsigned x, int n);

int main(void)
{

    unsigned    decimalX        =   53;
    int         numberOfBits    =   3;

    printf("decimal rotated: \n%u\n", rightrot(decimalX, numberOfBits));
    return 0;

}

unsigned rightrot (unsigned x, int n){
    while (n > 0){
        if ((x & 1) == 1){
            x = ((x >> n | ((x & ~(~0u << n)) << (8 -n))));
        }
        --n;    
    }
    return x;
}