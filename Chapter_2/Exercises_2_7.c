#include <stdio.h>

/*Write a function invert_bits(x, p, n, y) that return x with the n bits
that begin at position p inverted.

1 => 0 and viceversa leaving the others unchanged
* ~(~0 << n) => all ones are in in the rightmost position

*/

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c\n"
#define BYTE_TO_BINARY(byte)  \
  (byte & 128 ? '1' : '0'), \
  (byte & 64  ? '1' : '0'), \
  (byte & 32  ? '1' : '0'), \
  (byte & 16  ? '1' : '0'), \
  (byte & 8   ? '1' : '0'), \
  (byte & 4   ? '1' : '0'), \
  (byte & 2   ? '1' : '0'), \
  (byte & 1   ? '1' : '0') 

unsigned int invert_bits(int x, int p, int n);

int main(){

    int x = 0b11111111;

    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x));
    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(invert_bits(x, 2, 4)));

}

unsigned int invert_bits(int x, int p, int n){
    //printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x ^ (~0 << n)));
    //printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x ^ ~(~0 << n)));
    //printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x ^ ~(~0 << n) << (p+1-n)));
    return x ^ ~(~0 << n) << p;
}