#include <stdio.h>
#include <string.h>

#define MAXLINE 10000

int binsearch(int x, int v[], int n);


int main(){

    int v[MAXLINE];
    int x = 4;
    int i;

    for (i = 0; i < MAXLINE; ++i){
        v[i] = i;
    }   
    printf("binary search found: %d\n", binsearch(x, v, MAXLINE));
}

int binsearch(int x, int v[], int n){
    int low , high, mid;
    low = 0;
    high = n - 1;

    while (low <= high){
        mid = (low + high) /2;
        if (x < v[mid]){
            high = mid - 1;
        }
        else if (x > v[mid]){
            low = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}