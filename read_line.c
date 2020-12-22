#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

char *read_line(void);

int main(void){
    char *line;

    line = read_line();
    printf("%s\n", line);

    free(line);
    return 0;
}

char *read_line(void){
    int bufsize = BUF_SIZE;
    char *buffer;
    buffer = malloc(sizeof(char) * bufsize);
    int position = 0;
    int c;

    if (!buffer){
        fprintf(stderr, "read_line: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while(1){
        c = getchar();

        // if hit EOF or hit new line character
        if (c == EOF || c == '\n'){
            buffer[position] = '\0';
            return buffer;
        } else{
            buffer[position] = c;
        }
        position++;
    }

    // if we exceed the buffer ->reallocate
    if (position >= bufsize){
        bufsize += BUF_SIZE;
        buffer = realloc(buffer, bufsize);
        if (!buffer){
            fprintf(stderr, "read_line: allocation error\n");
            exit(EXIT_FAILURE);
        }
    }

}