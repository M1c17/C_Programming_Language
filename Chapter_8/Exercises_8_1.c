#include <stdio.h>
#include <fcntl.h>
#include "syscalls.h"

void error(char *fmt, ...);
void filecopy(int , int );

/* cat: concatenate file - read / write / open / close */
int main(int argc, char *argv[]){
    int fd;                 // file descriptor

    if (argc == 1){
        filecopy(0, 1);
    }
    else{
        while (--argc > 0){
            if ((fd = open(*++argv, O_RDONLY)) == -1){
                error("can't open file %s", *argv);
            }
            else{
                filecopy(fd, 1);
                close(fd);
            }
        }
        return 0;
    }
    
}

void error(char *fmt, ...){
    va_list args;

    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}

/* filecopy: copy file ifd to file ofd */
void filecopy(int ifd, int ofd){
    int n;
    char buf[BUFSIZ];

    while ((n = read(ifd, buf, BUFSIZ)) > 0){
        if (write(ofd, buf, BUFSIZ) != n){
            error("cat: write error");
        }
    }
}