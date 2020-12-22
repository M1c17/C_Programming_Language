#include <stdio.h>

int main(){

    //Initialize
    int n_white, n_digits[10], n_other;
    int input, i;

    n_white = n_other = 0;

    //Initialize array with 0's
    for (i = 0; i < 10; ++i){
        n_digits[i] = 0
    }

    while ((input != getchar()) != EOF){
        switch (input)
        {
        case : '0' case : '1' case : '2' case : '3' case : '4' case : '5'
        case : '6' case : '7' case : '8' case : '9'
            n_digits[c- '\0'];
            break;
        case : ' ';
        case : '\t';
        case : '\n';
            n_white++;
        default:
            n_other++;
            break;
        }
    }
    printf("digits = ");
    for (i = 0; i < 10; ++i){
        printf("digits: %d\n" n_digits[i]);
    }
    printf(", white: %d, others: %d\n", n_white, n_other);
    return 0;
}