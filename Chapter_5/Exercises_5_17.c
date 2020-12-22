#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXLEN 1000
#define MAXLINE 1000
#define MAXSTR 100
#define NUMERIC 1
#define DECR 2
#define FOLD 4
#define DIRECT 8

/*
Add a field-handling capability, so sorting may be done on fields
within lines, each field sorted according to an independet set of 
options. (The index for this book was sorted with -df for the index 
category and -n page numbers.)
*/

int get_line(char *line, int maxlen);
int  readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int n_lines, int decr);
void swap(void *s[], int i, int j);
void quicksort(void *s[], int left, int right, int (*comp)(void*, void*));
int num_cmp(char *n1, char *n2);
// int str_cmp(char *s1, char *s2);
int char_cmp(char *c1, char *c2);
int direct_cmp(char *s1, char *s2);

void error(char *);
void readargs(int argc, char *argv[]);

static char option = 0;
int pos1 = 0;               // field beginning with pos1
int pos2 = 0;               // ending just before pos2

int main(int argc, char *argv[]){

    char *lineptr[MAXLINE];
    int r_input = 0, n_lines;

    readargs(argc, argv);
    if ((n_lines = readlines(lineptr, MAXLINE)) > 0){
        if (option & NUMERIC){
            quicksort((void **) lineptr, 0, n_lines -1, (int (*)(void *, void*)) num_cmp);
        }
        else{
            quicksort((void **) lineptr, 0, n_lines -1, (int (*)(void *, void*)) char_cmp);
        }
        writelines(lineptr, n_lines, option & DECR);
    }
    else{
        printf("Error: Line too big to sort.\n");
        r_input = -1;
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

/*substring: get a substring of s and put in str */
void substr(char *s, char *str){
    int i, j, len;
    extern int pos1, pos2;

    len = strlen(s);
    if (pos2 > 0 && len > pos2){
        len = pos2;
    }
    else if (pos2 > 0 && len < pos2){
        error("substr: string too short");
    }
    //put substring into string
    for (j = 0, i = pos1; i < len; i++, j++){
        str[j] = s[i];
    }
    str[j] = '\0';
}

int num_cmp(char *n1, char *n2){
    double v1, v2;
    char str[MAXSTR];

    substr(n1, str);
    v1 = atof(str);
    substr(n2, str);
    v2 = atof(str);
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

// int str_cmp(char *s1, char *s2){
//     int i;

//     for (i = 0; s1[i] == s2[i]; i++){
//         if (s1 == '\0'){
//             return 0;
//         }
//     }
//     return s1[i] - s2[i];
// }

int char_cmp(char *s, char *t){
    char a, b;
    int i, j, endpos;
    extern char option;
    extern int pos1, pos2;
    int fold = (option & FOLD)? 1:0;
    int dir = (option & DIRECT)? 1:0;

    i = j = pos1;
    if (pos2 > 0){
        endpos = pos2;
    }
    else if((endpos = strlen(s) > strlen(t))){
        endpos = strlen(t);
    }
    do
    {
        if(dir){
            while (i < endpos && !isalnum(s[i]) && !isspace(s[i]) && s[i] != '\0'){
                i++;
            }
            while (j < endpos && !isalnum(t[j]) && !isspace(t[j]) && t[j] !=  '\0'){
                j++;
            }
        }
        if(i < endpos && j < endpos){
            a = fold ? tolower(s[i]) : s[i];
            i++;
            b = fold ? tolower(t[j]) : t[j];
            j++;
            if (a == b && a == '\0'){
                return 0;
            }
        }
    } while (a == b && i < endpos && j < endpos);
    return a - b; 
}


void error(char *error_str){
    printf("%s\n", error_str);
}

void readargs(int argc, char *argv[]){

    int input;

    while ((--argc > 0 && (input = (*++argv)[0]) == '-') || input == '+'){
        if (input == '-' && !isdigit(*(argv[0]+1))){
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
                case 'd':
                    option |= DIRECT;
                    break;
                default:
                    printf("Illegal command argument %c\n", input);
                    error("Usage: sort -dfnr [+pos1][-pos2]");
                    break;
                }
            }
        }
        else if(input == '-'){
            pos2 = atoi(argv[0]+1);
        }
        else if((pos1 = atoi(argv[0]+1)) < 0){
            error("Usage: sort -dfnr [+pos1][-pos2]");
        }
    }
    if (argc || pos1 > pos2){
        error("Usage: sort -dfnr [+pos1][-pos2]");
    }
}
