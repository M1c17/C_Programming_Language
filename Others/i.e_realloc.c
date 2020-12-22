#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);
    int *A = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        A[i] = i+1; 
    }

    // int *B = (int*)realloc(A, (n/2)*sizeof(int));
    int *B = (int*)realloc(A, 0); //equivalent to free(A)
    //create a new block 
    int *B = (int*)realloc(NULL, n*sizeof(int)); //equivalent to malloc 
    printf("Prev block address = %d, new address = %d\n" , *A, *B);
    for (int i = 0; i < n; i++){
        printf("%d\n", B[i]);
    }



}
