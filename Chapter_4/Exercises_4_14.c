#include <stdio.h>

/* Define a macro swap that interchanges two arguments
of type t */

#define swap(t, x, y) { t temp;     \
                        temp = x;   \
                        x    = y;   \
                        y    = temp;}

int main(){

    int x = 9;
    int y = 5;
    swap(int, x, y);
    printf("x= %d\n", x);
    printf("y= %d\n", y);
}