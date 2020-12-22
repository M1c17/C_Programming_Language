#include <stdio.h>

/*Write a program to "fold" long input lines into two o more
shorter lines after the last non-blank character that occurs 
before the n-th column of input. */

#define MAXCOLUMN 10
#define TABINC 8

char line[MAXCOLUMN];

int exp_tab(int pos);
int find_blnk(int pos);
int new_pos(int pos);
void print_line(int pos);

/* fold long input lines into two or more shorter lines */
int main(){
    int input, position = 0;

    while ((input = getchar()) !=EOF){
        line[position] = input;
        if (input == '\t'){
            position = exp_tab(position);
        }
        else if(input == '\n'){
            print_line(position);
            position = 0;
        }
        else if(++position >= MAXCOLUMN){
            position = find_blnk(position);
            print_line(position);
            position = new_pos(position);
        }  
    }
    return 0;   
}

/*expand tabs into blanks */
int exp_tab(int pos){
    line[pos] = ' ';                //Initialize line position
    for (++pos; pos < MAXCOLUMN && pos % TABINC != 0; ++pos){
        line[pos] = ' ';
    }
    if(pos < MAXCOLUMN){
        return pos;
    }
    else{
        print_line(pos);
        return 0;
    }
}

/*find blank's position */
//input : int pos output : int : pos
int find_blnk(int pos){
    while (pos > 0 && line[pos] != ' '){
        --pos;
    }
    if (pos == 0){              //no blanks in the line?
        return MAXCOLUMN;
    }
    else
    {
        return pos + 1;         //position after the blank
    }
    
}

/* rearrage line with new position */
int new_pos(int pos){
    int i, j;

    if(pos <= 0 || pos >= MAXCOLUMN){      //boundaries
        return 0;
    }
    else{                               //put in position 0 the input position 
        i = 0;
        for(j = pos; j < MAXCOLUMN; ++j){
            line[i] = line[j];
            ++i;
        }
        return i;
    }
}
/*print line unitl position column */
void print_line(int pos){
    int i;

    for (i = 0; i < pos; ++i){
        putchar(line[i]);
    }
    if (pos > 0){
        putchar('\n');
    }
}