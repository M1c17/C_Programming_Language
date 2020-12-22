#include <stdio.h>
#include <string.h>

#define MAXLEN 5
#define MAXLINE 100
#define MAXSTORAGE 1000

int get_line(char *line, int maxline);
int readlines(char *lineptr[], char *linestorage, int maxline);
void writelines(char *lineptr[], int count_lines);

int main(){

    char *lineptr[MAXLINE];
    char linestorage[MAXSTORAGE];
    int count_lines;

    count_lines = readlines(lineptr, linestorage, MAXLINE);
    writelines(lineptr, count_lines);
    return 0;

}

int get_line(char *line, int maxlen){
    int input, i;

    for (i = 0; i < maxlen - 1 && (input = getchar()) != EOF && input != '\n'; i++){
        printf("%d %c \n", i, input);
        line[i] = input;
    }
    if (input == '\n'){
        line[i++] = input;
    }
    line[i] = '\0';
    return i;
}


int readlines(char *lineptr[], char *linestorage, int maxline){

    int len, count_lines = 0;
    char *p;
    char line[MAXLEN];
    char *linestop = linestorage + MAXSTORAGE;

    p = linestorage;

    while ((len = get_line(line, MAXLEN)) > 0){
        printf("len: %d\n", len);
        if (count_lines >= MAXLINE || p + len > linestop){
            return -1;
        }
        else{
            //printf("length %d \n", len);
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[count_lines++] = p;
            p += len;

        }
    }
    return count_lines;
}

void writelines(char *lineptr[], int count_lines){

    int i;

    for (i = 0; i < count_lines; i++){
        printf("Line #%d: %s\n", i, lineptr[i]);
    }
}
