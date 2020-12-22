#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

/* 
Modify the pattern finding program of Chapter 5 to take its input from a set
of named files or, if no files are named as argments, from the standard input.
Should the file name be printed when a matching line is found?
*/

void fpatt(FILE *, char *, char *, int , int);

/* find: print lines that match pattern from 1st argument */
int main(int argc, char *argv[]){
    char pattern[MAXLINE];
    int input, except = 0, number = 0;
    FILE *fp;

    //printf("here0: %c\n", (*++argv)[0]);
    //printf("argv: %c\n", *++argv[0]);
    while (--argc > 0 && (*++argv)[0] == '-'){
        while ((input = *++argv[0])){
            switch (input)
            {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illegal coption\n");
                argc = 0;
                break;
            }
        }
    }

    if (argc >= 1){
        printf("here1: %s\n", *argv);
        strcpy(pattern, *argv);
    }
    else{
        printf("Usage: find [-x] [-n] pattern [file ...]\n");
        exit(1);
    }
    // no argv -> read from stdin
    if (argc == 1){
        fpatt(stdin, "", pattern, except, number);
    }
    else{
        // get a name file
        while (--argc > 0){
            if ((fp = fopen(*++argv, "r")) == NULL){
                fprintf(stderr, "find: can't open file %s\n", *argv);
                exit(1);
            }
            else{
                fpatt(fp, *argv, pattern, except, number);
                fclose(fp);
            }
        }
    }

}

/* fpatt: find pattern */
void fpatt(FILE *fp, char *fname, char *pattern, int except, int number){
    char line[MAXLINE];
    long nline = 0;

    while ((fgets(line, MAXLINE, fp)) != NULL){
        ++nline;
        if ((strstr(line, pattern) != NULL) != except){
            if(*fname){
                printf("%s -", fname);
            }
            if (number){
                printf("%ld: ", nline);
            }
            //printf("here except\n");
            printf("%s", line);
        }
    }
}

