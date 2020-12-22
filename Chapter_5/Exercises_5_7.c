#include <stdio.h>
#include <string.h>

#define MAXLEN      100
#define MAXLINE    1000
#define MAXSTORAGE 1000

/* Rewrite readlines to store lines in an array supplied by main rather 
than calling alloc to maintain storage. How much faster is the program ? */

int get_line(char line[], int maxlen);
int readline(char *lineptr[], char *linestorage, int maxlines);

void swap(char *lineptr[], int i, int j);

int partition(char *lineptr[], int left, int right);
void quicksort(char *lineptr[], int left, int right);
void writelines(char *lineptr[], int n_lines);

char *lineptr[MAXLINE];

int main(){

    //array for storing all lines
    char linestorage[MAXSTORAGE];
    int n_lines;

    if ((n_lines = readline(lineptr, linestorage, MAXLINE)) > 0){
        quicksort(lineptr, 0 , n_lines-1);
        writelines(lineptr, n_lines);
        return 0;
    }
    else{
        printf("Error: not enough space to store line\n");
        return 1;
    }
}

int get_line(char line[], int maxlen){
    int input, i;

    for (i = 0; i < maxlen - 1 && (input = getchar()) != EOF && input != '\n'; i++){
        line[i] = input;
    }
    if (input == '\n'){
        line[i++] = input;
    }
    line[i] = '\0';
    return i;

}

/* return number of lines */
int readline(char *lineptr[], char *linestorage, int maxlines){

    int len, n_lines = 0;
    char line[MAXLEN];
    //point to first empty position of linestorage
    char *p  = linestorage;
    char *linestop =  linestorage + MAXSTORAGE;

    printf("%s", linestorage);

    while ((len = get_line(line, MAXLEN)) > 0){
        if((n_lines >= MAXLINE) || p + len >= linestop){
            return -1;
        }
        else{
           line[len - 1] = '\0';
           strcpy(p, line);
           lineptr[n_lines++] = p;
           //point p to next empty position 
           p += len;   
        }
    }
    return n_lines;
}

void swap(char *lineptr[], int i, int j){
    char *temp;

    temp = lineptr[i];
    lineptr[i] = lineptr[j];
    lineptr[j] = temp;
}

int partition(char *lineptr[], int left, int right){
    int pivot = right, i;
    int partitionIndex = left;

    for (i = left; i < right; i++){
        if ((strcmp(lineptr[i], lineptr[pivot])) < 0){
            swap(lineptr, i, partitionIndex++);
        }
    }
    swap(lineptr, partitionIndex, right);
    return partitionIndex;
}

void quicksort(char *lineptr[], int left, int right){
    int indexpartition;

    if (left >= right){
        return;
    }
    indexpartition = partition(lineptr, left, right);
    quicksort(lineptr, left, indexpartition-1);
    quicksort(lineptr, indexpartition+1, right);

}
void writelines(char *lineptr[], int n_lines){

    int i;

    for (i = 0; i < n_lines; i++){
        printf("line # %d: %s\n", i, lineptr[i]);
    }
}

