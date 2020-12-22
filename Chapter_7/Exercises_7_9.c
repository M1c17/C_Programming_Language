#include <stdio.h>

/* This version saves time and uses more space */
#define isupper_macro(c) ((c >= 'A') && (c <= 'Z')? 1:0)

/*
Functions like isupper can be implemented to save space or to save time.
Explore both possibilities 
*/
int isupper_function(char );
int isupper_function_1(char );

int main(){

    char c = 'H';

    printf("isupper_macro(%c): %d\n", c, isupper_macro(c));
    printf("isupper_function(%c): %d\n", c, isupper_function(c));
    printf("isupper_function_1(%c): %d\n", c, isupper_function_1(c));

    c = 'h';

    printf("isupper_macro(%c): %d\n", c, isupper_macro(c));
    printf("isupper_function(%c): %d\n", c, isupper_function(c));
    printf("isupper_function_1(%c): %d\n", c, isupper_function_1(c));

    return 0;
}

/* isupper: return 1 (true) if c is an upper case letter 
This version saves space */
int isupper_function(char c){
    if (c >= 'A' && c <= 'Z'){
        return 1;
    }
    else{
        return 0;
    }   
}

int isupper_function_1(char c){
    return (c >= 'A' && c <= 'Z');
}

