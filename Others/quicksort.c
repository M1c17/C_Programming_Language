#include <stdio.h>
#include <string.h>

void quicksort(int s[], int left, int right);
void swap(int s[], int i, int j);

int main(){

    int s[] = {7,2,1,6,8,5,3,4};
    quicksort(s, 0, 7);

    for (int i = 0; i < 8; i++){
        printf("%d ", s[i]);
    }

}

void swap(int s[], int i, int j){
    int temp;

    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

void quicksort(int s[], int left, int right){
    int i, partitionIndex;

    if (left >= right){                         //Base case to exit loop
        return;
    }                                           
    //swap(s, left, (left + right)/2);          // put pivot in the middle of array
    partitionIndex = left;                      // start partition 
    for (i = left; i < right; i++){        
        if (s[i] < s[left]){                    // pivot => left = v[0]
            swap(s, ++partitionIndex, i);       // swap i if ++i < left
        }                        
    }
    swap(s, left, partitionIndex);               // swap pivot with partitionIndex
    quicksort(s, left, partitionIndex-1);        // sort left elements
    quicksort(s, partitionIndex+1, right);       // sort right elements

}
