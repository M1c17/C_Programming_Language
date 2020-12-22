#include <stdio.h>

/*
If there are command-line arguments, they are interpreted as files names,
and processed in order.
If there are no arguments the standard input is processed 
*/

/*cat: concatenate files, version 1 */

void filecopy(FILE *, FILE *);

int main(int argc, char *argv[]){
    FILE *fp;

    // no args; copy stdin 
    if (argc == 1){
        filecopy(stdin, stdout);
    }
    else{
        while (--argc > 0){
            if ((fp = fopen(*++argv, "r")) = NULL){
                printf("cat: can't open %s\n", *argv);
                return 1;
            }
            else{
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    return 0;
}

/*filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp){
    int input;

    while ((input = getc(ifp)) != EOF){
        putc(input, ofp);
    }
}