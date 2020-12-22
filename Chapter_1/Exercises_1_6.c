#include <stdio.h>

/*Verify that the expression getchar() !=EOF
is 0 or 1. */

int main(){
    
    printf("Please, Input a char:\n");
    int c = getchar();
    printf("Value of expr: %d\n", c != EOF);
    return 0;
}

/* 
- If your input is not EOF Then will print 1
- else will print 0
- EOF => end of the file 
*/