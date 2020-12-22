#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte) \
    (byte & 128 ? '1' :'0'), \
    (byte & 64 ?  '1' :'0'), \
    (byte & 32 ?  '1' :'0'), \
    (byte & 16 ?  '1' :'0'), \
    (byte & 8 ?   '1' :'0'), \
    (byte & 4 ?   '1' :'0'), \
    (byte & 2 ?   '1' :'0'), \
    (byte & 1 ?   '1' :'0')

int count_bit(unsigned int x);

int main(){
    unsigned int x = 0b011010;

    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x));
    printf("\nthere are %d, 1's bit in x\n", count_bit(x));
}

int count_bit(unsigned int x){
    int b;

    for(b = 0; x!= 0; x &= x-1){
        b++;
    }
    return b;
}