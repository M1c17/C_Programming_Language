#include <stdio.h>

#define MAXLINE 1000

int bin_search(int x, int v[], int n);

int main(){

    int v[MAXLINE];
    int x = 4;
    int i;

    for (i = 0; i < MAXLINE; ++i){
        v[i] = i;
    }
    printf("bin search found: %d\n", bin_search(x, v, MAXLINE));   
}

int bin_search(int x, int v[], int n){

    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low < high && x != v[mid]){
        mid = (low + high)/2;
        if (x < v[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        } 
    }
    if (x == v[mid]){
        return mid;
    }
    else{
        return -1;
    }    
}