#include <stdio.h>

/*Count digits, white space, others */
int main(){

    printf("Please, Enter a input and after that Ctrl + D:\n");
    int input, i, blanks, other;
    int number_of_digits[10];

    blanks = other = 0;
    for(i = 0; i < 10; ++i){
        number_of_digits[i] = 0;
    }
    while((input = getchar()) != EOF){
        if(input >= '0' && input <= '9'){
            ++number_of_digits[input - '0'];
        }
        else if(input == ' ' || input == '\n' || input == '\t'){
            ++blanks;
        }
        else{
            ++other;
        }
    }
    printf("digits =");
    for(i = 0; i < 10; ++i){
        printf(" %d", number_of_digits[i]);
        }
        printf(" ,white space = %d, other = %d\n", blanks, other);
}