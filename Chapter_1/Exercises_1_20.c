 #include <stdio.h>

#define TABINC 8        // \t increment size

 /*write a program detab that replaces tabs in the input
 with the proper number of blanks to space to the next tab stop.
 Assume a fixed set of tab stops, say every n columns.
 should n be a variable or a symbolic parameter?. */

  // each \t that occurs should be replace by n spaces
 int main(){

     //Ask user for input
     printf("Please, Enter a input and after that Ctrl + D:\n");
     //Initialize
     int input, number_blanks, position;

     number_blanks = 0;         // number of blanks 
     position = 0;              // position of character in line

     while ((input = getchar()) !=EOF){
         if (input == '\t'){

            // formula to calculate number of blanks need it 
            // multiple with TABINC
            number_blanks = TABINC - (position % TABINC);
            while(number_blanks > 0){
                putchar('*');
                ++position;
                --number_blanks;
            }
         }
         else if (input == '\n'){       
             putchar(input); 
             position = 0;          //reset the position
         }
         else{
             putchar(input);
             ++position;
         }   
     }
     return 0;
 }
