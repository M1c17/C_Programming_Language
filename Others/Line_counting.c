#include <stdio.h>

/* count lines in input */
int main()
{
    printf("Please, Enter some char:\n");
    int input;
    int count = 0;

    while(input = getchar()) != EOF){
        if(input == '\n'){
             ++count;
        }
    }
    printf("count is: %d\n", count);
    return 0;
}