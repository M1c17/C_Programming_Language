#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define MAXSTORAGE 5000

/* Write a program that sort the input lines numerically instead 
of lexicographical given the optional argument -n */

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int n_lines);
void quicksort(void *lineptr[], int left, int right, 
              int (*comp)(void *, void *));
int num_cmp(char *s1, char *s2);
void swap(void *s[], int i, int j);
int str_cmp(char *s, char *t);


char *lineptr[MAXLINES];

int main(int argc, char *argv[]){
    int n_lines;            //number of input lines read
    int numeric = 0;        //1 if numeric sort


    if (argc > 1 && strcmp(argv[1], "-n") == '0'){
        numeric = 1;
    }
    if ((n_lines = readlines(lineptr, MAXLINES)) > 0){
        quicksort((void **) lineptr, 0, n_lines - 1, (int (*)(void*, void*))(numeric ?  num_cmp : str_cmp));
        writelines(lineptr, n_lines);
        return 0;
    }
    else{
        printf("Error: input too big to sort\n");
        return 1;
    }
}

int str_cmp(char *s, char *t){
    int i;

    for (i = 0; s[i] == t[i]; i++){
        if (s[i] == '\0'){
            return 0;
        }
    }
    return s[i] - t[i];
}

int get_line(char *line, int maxlines){
    int input, i;

    for (i = 0; i < maxlines - 1 && (input = getchar()) != EOF && input != '\n'; i++){
        line[i] = input;
    }
    if(input == '\n'){
        line[i++]  = input;
    }
    line[i] = '\0';
    return i;
}

int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = get_line(line, MAXLEN)) > 0)
       if(nlines >= maxlines || (p = malloc(len)) == NULL)
          return -1;
       else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
       }
    return nlines;
}

void writelines(char *lineptr[], int n_lines){

    int i;

    for (i = 0; i < n_lines; i++){
        printf("line # %d: %s\n", i, lineptr[i]);
    }
}

void swap(void *s[], int i, int j){
    char *temp;

    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

void quicksort(void *s[], int left, int right, int (*comp)(void *, void *)){

    int pivot = right, i;
    int partionIndex = left;

    if (left >= right){
        return;
    }
    for (i = left; i < right; i++){
        if((*comp)(s[i], s[pivot]) < 0){
            swap(s, i, partionIndex++);
        }
    }
    swap(s, partionIndex, right);
    quicksort(s, left, partionIndex - 1, comp);
    quicksort(s, partionIndex + 1, right, comp);

}

int num_cmp(char *s1, char *s2){

    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2){
        return -1;
    }
    else if(v1 > v2){
        return 1;
    }
    else{
        return 0;
    }
}
