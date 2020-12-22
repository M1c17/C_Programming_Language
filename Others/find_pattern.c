#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_line(char *line, int maxline);

/*find: print lines that match pattern for the first arg */

int main(int argc, char *argv[]){
    char line[MAXLINE];
    long lineno = 0;
    int input, except = 0,  number = 0, found = 0;

    //(*++argv)[0] => pointer to the first character of the string
    while (--argc > 0 && (*++argv)[0] == '-'){
        //go to the next pointer string and store input
        while ((input = *++argv[0])){
            switch (input) {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            
            default:
                printf("find: Illegal option %c\n", input);
                argc = 0;
                found = -1;
                break;
            }
        }
    }
    
    if (argc != 1){
        printf("Usage: find -x -n pattern\n");
    }
    else{
        while (get_line(line, MAXLINE) > 0){
            lineno++;
            if ((strstr(line, *argv) != NULL) != except){
                if(number){
                    printf("%ld", lineno);
                }
                printf("%s", line);
                found++;
            }
        }
    }
    return found;
}

int get_line(char *line, int maxline){

    int input, i;

    for (i = 0; i < maxline - 1 && (input = getchar()) != EOF && input != '\n'; i++){
        line[i] = input;
    }
    if (input == '\n'){
        line[i++] = input;
    }
    line[i] = '\0';
    return i;
}