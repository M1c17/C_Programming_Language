#include <stdio.h>
#include <stdlib.h>

/*
Write a program to print a set of files, starting each new one on a new page,
with a title and a running page count for each file.
*/

#define MAXBOT 3        // maximun # lines at bottom page
#define MAXHDR 5        // maximum # lines at head of page
#define MAXLINE 100     // maximum size of one line
#define MAXPAGE 50      // maximum # lines on one page

void fprint(FILE *, char *fname);

/* print: print files - each new one on a new page */
int main(int argc, char *argv[]){
    FILE *fp;

    if (argc == 1){
        fprint(stdin, " ");
    }
    else{
        while (--argc > 0){
            if ((fp = fopen(*++argv, "r")) == NULL){
                printf("fprint: can't open file %s\n", *argv);
            }
            else{
                fprint(fp, *argv);
                fclose(fp);
            }
        }
    }
    return 0;
}

/* heading: put heading and enough blank lines */
int heading(char *fname, int npage){

    int ln = 3;
    fprintf(stdout, "\n\n");
    fprintf(stdout, "%s     page %d\n", fname, npage);
    while (ln++ < MAXHDR){
        fprintf(stdout, "\n");
    }
    printf("ln: %d\n", ln);
    return ln;
}

/* fprint: print file name */
void fprint(FILE *fp, char *fname){
    int nline, npage = 1;
    char line[MAXLINE];

    nline = heading(fname, npage++);
    printf("nline0: %d\n", nline);
    while (fgets(line, MAXLINE, fp) != NULL){
        if (nline == 1){
            fprintf(stdout, "\f");
            nline = heading(fname, npage++);
            printf("nline1: %d\n", nline);
        }
        fputs(line, stdout);
        // 
        if (++nline > MAXPAGE - MAXBOT){
            printf("nline2: %d\n", nline);
            // reset
            nline = 1;
        }
    }
    printf("nline3: %d\n", nline);
    fprintf(stdout, "\f");                  // page eject after the file
}

