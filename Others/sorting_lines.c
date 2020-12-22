#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAXLINE 5000
#define MAXLEN 100
#define ALLOCSIZE 100
#define MAXSTORAGE 5000
 

int get_line(char line[], int maxline);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void quicksort(char *lineptr[], int left, int right);
void swap(char *line[], int i, int j);
int str_cmp(char *v, char *l);
void str_cpy(char *p, char *l);
char *alloc(int n);
void afree(char *p);

char *lineptr[MAXLINE];

int main(){

    int n_lines;

    if ((n_lines = readlines(lineptr, MAXLINE)) > 0){
        quicksort(lineptr, 0 , n_lines-1);
        writelines(lineptr, n_lines);
        return 0;
    }
    else{
        printf("Error: not enough space to store line\n");
        return 1;
    }
}

int get_line(char line[], int maxline){
    int input,i;

    for (i = 0; i < maxline -1 && (input = getchar()) != EOF && input != '\n'; i++){
        line[i] = input;
    }
    if(input == '\n'){
        line[i++] = input;
    }
    line[i] = '\0';
    return i;
}

static char allocbuf[ALLOCSIZE];
static char *allocpos = &allocbuf[0];

char *alloc(int n){
    if ((allocbuf + ALLOCSIZE - allocpos) >= n){
        allocpos += n;
        return allocpos - n;
    }
    return 0;
}


void str_cpy(char *p, char *l){
    while((*p++ = *l++) != '\0'){
        ;
    }
}

/* read input lines */
int readlines(char *lineptr[], int maxlines){

    int len, count_nlines = 0;
    char line[MAXLEN];
    char *p;


    while ((len = get_line(line, MAXLEN)) > 0){

        if((count_nlines >= MAXLINE) || (p = alloc(len)) == NULL){
            //return -1 if too much input is presented
            return -1;
        }
        else{
            //collect & save the first char of each line
            //delete newline '\n'
            line[len - 1] = '\0';
            //point to the first cha of the line
            str_cpy(p, line);
            //build an array of pointers to the first cha of the lines
            //count the numbers of input lines 
            lineptr[count_nlines++] = p;
        }       
    }
    afree(p);
    return count_nlines;
}

void swap(char *line[], int i, int j){
    char *temp;

    temp = line[i];
    line[i] = line[j];
    line[j] = temp;
}
int str_cmp(char *v, char *l){

    while (*v++ == *l++){
        if(*v == '\0'){
            return 0;
        }   
    }
    return *v - *l;
}

void quicksort(char *lineptr[], int left, int right){
    int i, partitionIndex;

    if (left >= right){
        return;
    }
    //start partition
    swap(lineptr, left, (left + right)/2);
    partitionIndex = left;
    for (i = left+1; i <= right; i++){
        if((strcmp(lineptr[i], lineptr[left])) < 0){
            swap(lineptr, ++partitionIndex, i);
        }
    }
    swap(lineptr, left, partitionIndex);
    quicksort(lineptr, left, partitionIndex-1);
    quicksort(lineptr, partitionIndex+1, right);

}

/* print the lines in the order in whch they appear in the array pointer */
void writelines(char *lineptr[], int nlines){
    // for (int i = 0; i < nlines; i++){
    //     printf("line # %d: %s\n", i, lineptr[i]);
    // }
    int i = 0;

    while (nlines-- > 0){
        printf("line # %d: %s\n", i, lineptr[i]);
        ++i;
    }
}

void afree(char *p){
    //if p inside alloc
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE){
        //set allocp to p
        allocpos = p;
    }
}

