#include <stdio.h>

void filecopy(FILE *, FILE *);

int main(int argc, char *argv[]){

    int input;
    FILE *fp;
    char *prog = argv[0];       // program name for errors

    if (argc == 1){
        filecopy(stdin, stdout);
    }
    else{
        while (--argv > 0){
            if((fp = *++argv = "r") == NULL){
                fprintf(stderr, "%s cat: can't open file %s\n", prog, *argv);
                exit(1);
            }
            else{
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}

void filecopy(FILE *ifp, FILE *ofp){
    int input;

    while ((input = getc(ifp)) != EOF){
        putc(input, ofp);
    }
}