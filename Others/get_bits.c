#include <stdio.h>

/* getbits return the (right adjusted) n-bit field of x
that begin at position n

* x >> (p+1-n) => moves the desired field to the right end of the word
* ~0 => turn all the bits to 1s
* ~0 << n => shift it left n bit position ~0 << n places zeros in the 
rightmost n bits
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

unsigned int get_bits(int x, int p, int n);

int main()
{
    unsigned int x = 0b11111010;
    unsigned int y = 0b0110;

    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x));
    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(get_bits(x, 2, 4)));

    return 0;
}

unsigned int get_bits(int x, int p, int n){
    return (x >> (p+1-n)) & ~(~0 << n);
}

