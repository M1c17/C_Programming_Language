#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 100

/*
Write a program to compare two files, printing the first line where they differ.
*/

void filecomp(FILE *file1, FILE *file2);

int main(int argc, char *argv[]){
    FILE *file1, *file2;

    if (argc != 3){
        fprintf(stderr, "comp: needed 2 arguments file to proceed\n");
        exit(1);
    }
    else{
        if ((file1 = fopen(*++argv, "r")) == NULL){
            fprintf(stderr, "comp: can't open %s\n", *argv);
            exit(1);
        }
        else if((file2 = fopen(*++argv, "r")) == NULL){
            fprintf(stderr, "comp: can't open %s\n", *argv);
            exit(1);
        }
        else {
            filecomp(file1, file2);
            fclose(file1);
            fclose(file2);
            exit(0);
        }
    }
    return 0;
}
/*filecomp: compare two files - a line at a time */
void filecomp(FILE *file1, FILE *file2){
    char line1[MAXLINE], line2[MAXLINE];
    char *lp1, *lp2;

    do
    {
        lp1 = fgets(line1, MAXLINE, file1);
        lp2 = fgets(line2, MAXLINE, file2);
        if (lp1 == line1 && lp2 == line2){
            if (strcmp(line1, line2) != 0){
                printf("first difference in line: \n%s\n", line1);
                lp1 = lp2 = NULL;
            }
        }
        else if (lp1 != line1 && lp2 == line2){
            printf("end of first file at line \n%s\n", line2);
        }
        else if (lp1 == line1 && lp2 != line2){
            printf("end of second file at line \n%s\n", line1);
        }

    } while (lp1 == line1 && lp2 == line2);
}
