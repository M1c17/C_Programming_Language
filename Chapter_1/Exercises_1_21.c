#include <stdio.h>

/* Write program entab that replaces strings of blanks by the 
minimun number of tabs and blanks to achieve the same spacing.
Use the same tab stop as for detab.
When either a tab or single blank would suffice to reach a tab
stop, which should be given preference? */

#define TABINC 8

//A string of blanks is replace every time position reach a multiple of TABINC

int main(){
    //Initialize
    int input, i, number_blanks, position, number_tabs;

    number_blanks = 0;          // number of blanks needed
    number_tabs = 0;            // number of tabs needed
    //Ask for input
    printf("Please, Enter a input and after that Ctrl + D:\n");
    //get input and count positions
    for(position = 1; (input = getchar()) != EOF; ++position){
        if(input == ' '){
            if(position % TABINC != 0){
                ++number_blanks;        //increment number of blanks
            }
            else{
                number_blanks = 0;      //reset number of blanks 
                ++number_tabs;          //one tab needed   
            }
        }
        else{
            //print tabs 
            while (number_tabs > 0){
                --number_tabs;
                putchar('-');
            }
            if (input == '\t'){
                //putchar('-');
                number_blanks = 0;      // reset blanks
                //++number_tabs;    
            }
            else{
                //print blanks
                while (number_blanks > 0){
                    --number_blanks;
                    putchar('*');
                }
            }
            putchar(input);
            if (input == '\n'){
                position = 0;
            }
            else if (input == '\t'){
                // how many blanks do i need after finding tab 
                // space after tab
                position = position + (TABINC - (position - 1) % TABINC) - 1;
            }
        }   
    }
    return 0;
}