#include <stdio.h>
#include <string.h>

void shellsort(int v[], int n);

int main(){
    
    int i;
    int numbers[10] = {6, 7, 8, 2, 6, 1, 8, 9, 0, 2};

    shellsort(numbers, 10);
    for (i = 0; i < 10; i++){
        // printf("unsorted array: %d\n ", numbers[i]);
        printf("sorted array: %d\n", numbers[i]);
    }
}

void shellsort(int v[], int n){
    int gap, i, j, temp;

    //control the gap between compared elements 
    //shrinking it from n/2
    for (gap = n/2; gap > 0; gap /= 2){
        //steps along the elements
        for (i = gap; i < n; ++i){
            //compares each pair of elements that is separeted by gap 
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j-= gap){
                //reverse any that are out of order
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }

        }
    }
}