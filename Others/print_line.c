#include <stdio.h>

//program to print line

void print_line(int pos);

int main(){
    int n = 10;
    print_line(n);    
}

void print_line(int pos){
    int i;

    for(i = 0; i < pos; ++i){
        putchar('*');
    }
}