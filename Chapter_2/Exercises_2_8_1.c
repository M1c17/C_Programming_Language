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

    if((n = n % 8) > 0){                                    //if the n exceed 8 num bits then number of n is the remainder
        x = ((x >> n | ((x & ~(~0u << n)) << (8 -n))));
    }
    return x;
}

/*
* ((x & ~(~0u << n)) => n rightmost bits of x
                     => n rightmost bits to left

* (x >> n) = > x shifted n positions right
* ((x >> n | ((x & ~(~0u << n)) << (8 -n)))) => ORed to complete the rotation