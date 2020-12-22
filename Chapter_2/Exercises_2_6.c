#include <stdio.h>

/*Write a function setbits(x, p, n, y) that return x with the n bits that begin
at position p set to the right n bits of y, leaving the other bits unchaged 

* ~ => make a mask with ones to the  rightmost n bits

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

unsigned int set_bits(int x, int p, int n, int y);

int main(){

    int x = 0b11111111;
    int y = 0b001;

    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x));
    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(set_bits(x, 2, 4, y)));

}

unsigned int set_bits(int x, int p, int n, int y){

    unsigned int mask1 = x & ~(~(~0 << n) << p); 
    unsigned int mask2 = y & ~(~0 << n) << p;

     return mask1 | mask2;
}