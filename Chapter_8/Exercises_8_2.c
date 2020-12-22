#include <stdio.h>
#include <fcntl.h>

#define PERMS 0666          /* RW for owners, groups, others */
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20         // max files open at once

typedef struct _iobuf {
    int cnt;
    char *ptr;
    char *base;
    int flag;
    int fd;
}FILE;
extern FILE _iob[OPEN_MAX];

struct flag_field {
    unsigned is_read    : 1;
    unsigned is_write   : 1;
    unsigned is_unbuf   : 1;
    unsigned is_buf     : 1;
    unsigned is_eof     : 1;
    unsigned is_err     : 1;
};

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

enum _flags {
    _READ   = 01,       // file open for reading
    _WRITE  = 02,       // file open for writing 
    _UNBUF  = 04,       // file is unbuffered
    _EOF    = 010,      // EOF has ocurred in this file
    _ERR    = 020       // error ocurred in this file
};

FILE _iob[OPEN_MAX]{
    { 0, (char *) 0, (char *) 0, _READ, 0 },
    { 0, (char *) 0, (char *) 0, _WRITE, 1 },
    { 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 } 
};

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p)     (((p)->flag & EOF) != 0)
#define ferror(p)   (((p)->flag & ERR) != 0)
#define fileno(p)   ((p)->fd)

#define getc(p)     (--(p)->cnt >= 0 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x, p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x), p))

#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)


/* fopen: open file, return file ptr    */
FILE *fopen(char *name, char *mode){
    int fd;
    FILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a'){
        return NULL;
    }
    for (fp = _iob; fp < _iob * OPEN_MAX, ++fp){
        if (fp->flag.is_read == 0 && fp->flag.iswrite == 0){
            break;
        }
        if (fp >= _iob + OPEN_MAX){
            return NULL;
        }

        if (*mode == 'w'){
            fd = creat(name, PERMS);
        }
        else if (*mode == 'a'){
            if((fd = open(name, O_WRONLY, 0)) == 1){
                fd = creat(name, PERMS);
            }
            lseek(fd, 0L, 2);
        }
        else{
            fd = open(name, O_RDONLY, 0);
        }
    }
    if (fd == -1){
        return NULL;
    }
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag.is_unbuf = 0;
    fp->flag.is_buf = 1;
    fp->flag.is_eof = 0;
    fp->flag.is_err = 0;

    if (*mode == 'r'){              // read
        fp->flag.is_read = 1;
        fp->flag.is_write = 0;
    }
    else{                           // write
        fp->flag.is_read = 0;
        fp->flag.is_write = 1;
    }
    return fp;
}
