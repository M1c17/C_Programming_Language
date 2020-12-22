#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLEN 1000
#define MAXLINE 1000
#define NUMERIC 1
#define DECR 2
#define FOLD 4

/*
Add the option -f option, to fold upper and lower case together, so that case distinctions 
are not made during sorting; for example, a and A compare equal.
*/

int get_line(char *line, int maxlen);
int  readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int n_lines, int decr);
void swap(void *s[], int i, int j);
void quicksort(void *s[], int left, int right, int (*comp)(void*, void*));
int num_cmp(char *n1, char *n2);
int str_cmp(char *s1, char *s2);
int char_cmp(char *c1, char *c2);


static char option = 0;

int main(int argc, char *argv[]){

    char *lineptr[MAXLINE];
    int input, n_lines; 
    int r_input = 0;

    while (--argc > 0 && (*++argv)[0] == '-'){
        while ((input = *++argv[0])){
            switch (input)
            {
            case 'f':
                option |= FOLD;
                break;
            case 'n':
                option |= NUMERIC;
                break;
            case 'r':
                option |= DECR;
                break;
            default:
                printf("Illegal command argument %c\n", input);
                argc = 1;
                r_input = -1;
                break;
            }
        }
    }
    if (argc){
        printf("Usage sort -nrf\n");
    }
    else{
        if ((n_lines = readlines(lineptr, MAXLINE)) > 0){
            if (option & NUMERIC){
                quicksort((void **) lineptr, 0, n_lines -1, (int (*)(void *, void*)) num_cmp);
            }
            else if(option & FOLD){
                quicksort((void **) lineptr, 0, n_lines -1, (int (*)(void *, void*)) char_cmp);
            }
            else{
                quicksort((void **) lineptr, 0, n_lines -1, (int (*)(void *, void*)) str_cmp);
            }
            writelines(lineptr, n_lines, option & DECR);
        }
        else{
            printf("Error: Line too big to sort.\n");
            r_input = -1;
        }
    }
    return r_input;
}

int get_line(char *line, int maxlen){
    int input, i;

    for(i = 0; i < maxlen -1 && (input = getchar()) != EOF && input != '\n'; i++){
        line[i] = input;
    }
    if (input == '\n'){
        line[i++] = input;
    }
    line[i] = '\0';
    return i;
}

int readlines(char *lineptr[], int maxlines){

    char line[MAXLEN];
    int len, n_lines;
    char *p;

    while ((len = get_line(line, MAXLEN))  > 0){
        if (n_lines >= maxlines || (p = malloc(len)) == NULL){
            return 1;
        }
        else{
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[n_lines++] = p;
        }
    }
    return n_lines;
}

void writelines(char *lineptr[], int n_lines, int decr){

    int i;

    if (decr){
        for (i = n_lines - 1; i >= 0; i--){
            printf("# %d, line %s\n", i, lineptr[i]);
        }
    }
    else{
        for(i = 0; i < n_lines; i++){
            printf("# %d, line %s\n", i, lineptr[i]);
        }
    }
}

void swap(void *s[], int i, int j){
    char *temp;

    temp = s[i];
    s[i] = s[j];
    s[j] = temp;

}

void quicksort(void *s[], int left, int right, int (*comp)(void*, void*)){
    int pivot = right;
    int partionIndex = left;
    int i;

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

int num_cmp(char *n1, char *n2){
    double v1, v2;

    v1 = atof(n1);
    v2 = atof(n2);
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

int str_cmp(char *s1, char *s2){
    int i;

    for (i = 0; s1[i] == s2[i]; i++){
        if (s1 == '\0'){
            return 0;
        }
    }
    return s1[i] - s2[i];
}

int char_cmp(char *c1, char *c2){

    for( ; tolower(*c1) == tolower(*c2); c1++, c2++){
        if (c1 == '\0'){
            return 0;
        }
    }
    return tolower(*c1) - tolower(*c2);
}



