#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Write the program tail, which prints the last n lines of its input.
By default, n is 10, lets us say, but it can be changed by an optional
argument, so that 
                    tail -n
prints the last n lines. Write the program so it makes the best use of available
storage. */

#define DEFAULTN 10             //default n
#define MAXLEN 100              //max len of line
#define LINEMAX 100             //max # of lines to print

int get_line(char *line, int maxline);
void error(char *error_line);
void tail_n(char *line, int N);

int main(int argc, char *argv[]){
    int N;
    char line[MAXLEN];

    // i want to know if a have a argument command or if i need to use my default
    if (argc <= 1){
        N = DEFAULTN;
    }
    else if (argc == 2 && (*++argv)[1] == '-'){
        //N = atoi(*++argv);
        N = atoi(argv[0]+1);
    }
    else{
        error("Usage: tail [-n]");
    }
    tail_n(line, N);
    return 0;  
}

void error(char *error_line){
    printf("%s\n", error_line);
}

int get_line(char *line, int maxline){

    int input, i; 

    for (i = 0; i < maxline - 1 && (input = getchar()) != EOF && input != '\n'; ++i){
        line[i] = input;
    }
    if (input == '\n'){
        line[i] = input;
    }
    line[i] = '\0';
    return i;
}

/* print n lines of its input */
void tail_n(char *line, int N){

    //Initialize variables
    int i, count_lines, len;
    int first_line, last_line;

    char *p;                                            // pointer to keep track of size needded
    char *ptrarray[LINEMAX];                            // array pointer to each string

    char *buffer;                                       // size buffer
    char *buff_end;


    //boundaries: is a valid N?
    if (N < 1 || N > LINEMAX){
        N = LINEMAX;
    }
    //Initialize array ptr to NULL
    for (i = 0; i < LINEMAX; ++i){
        ptrarray[i] = NULL;
    }
    //boundaries: Is the buffer big enough?
    if ((p = buffer = malloc(LINEMAX * MAXLEN)) == NULL){
        error("tail: cannot allocate buffer");
    }
    buff_end = buffer + LINEMAX * MAXLEN;
    last_line = 0;
    count_lines = 0;

    //Start walking through the lines
    while ((len = get_line(line, MAXLEN)) > 0){
        // for each read line allocate space in the buffer
        // check if len of line is not greater than buffer
        if ((p + len + 1) >= buff_end){
            p = buffer;                            // reset pointer to the start of buffer
        }
        //put size to line ptr
        ptrarray[last_line] = p;
        //copy from line to ptr array
        strcpy(ptrarray[last_line], line);
        ++last_line;
        //check if the last line doesn't pass over the MAX LINE
        if (last_line > LINEMAX){
            last_line = 0;                          // reset last_line
        }
        p += len + 1;                               // last line size
        //count lines
        ++count_lines;
    }

    // check if the N given is greater than number of lines input
    if (N > count_lines){
        N = count_lines;
    }
    // where should start printing
    first_line = last_line - N;
    // check if you wrap around the list
    if (first_line < 0){
        first_line += LINEMAX;
    }
    // printf n last lines
    // the modulus operator mantain i between first_line and LINEMAX
    for (i = first_line; N-- > 0; i = (i + 1) % LINEMAX){
        printf("%s\n", ptrarray[i]);
    }
}

