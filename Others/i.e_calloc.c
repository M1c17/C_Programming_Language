#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter size of int array\n");
    scanf("%d", &n);
    int *A = (int*)calloc(n, sizeof(int));
    // calloc Initialize the array with zeros

    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
}