#include <stdio.h>

#define ALLOCSIZE 100

char *alloc(int n);

int main(){

}
static char allocbuf[ALLOCSIZE];      //storage for alloc
static char *allocp = &allocbuf[0];    //next free positions

/* return pointer to n char */
//argument n => size of memory you want 
char *alloc(int n){     
      
    if((allocbuf + ALLOCSIZE - allocp) >= n){   //if enough room left
        allocp += n;
        return allocp - n;          //old p
    } else{
        return 0;
    }
}

void afree(char *p){
    //if p inside alloc
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE){
        //set allocp to p
        allocp = p;
    }
}




