#include <stdio.h>

#define MAXLINE 1000

/*Write a function expand(s1 s2) => expand short hand notation.

*a-z => abc...xyz
*a-b-c => abc
*a-z0-9 => abc...xyz

*/

int get_line(char s1[], int maxline);
void expand(char s1[], char s2[]);

int main(){
    char s1[MAXLINE];
    char s2[MAXLINE];

    get_line(s1, MAXLINE);
    expand(s1, s2);
    printf("original line: %s\n", s1);
    printf("expand line: %s\n",  s2);

}

int get_line(char s1[], int maxline){
    int input, i;

    for (i = 0; i < maxline - 1 && (input = getchar()) != EOF && input !='\n'; ++i){
        s1[i] = input;
    }
    if (input == '\n'){
        s1[i] = input;
    }
    s1[i] = '\0';
    return i;
}

void expand(char s1[], char s2[]){
    //Initialize variables
    int i, j;
    char temp;

    //if any character and s1 is not \0
    for (i = j = 0; s1[i] != EOF; ++i){
        temp = s1[i++];
        //find '-' char to know where to expand s2
        if(s1[i] == '-' && s1[i+1] >= temp){
            ++i;
            //expand the short hand
            while (temp <= s1[i]){
                //skip numbers
                if (s1[i] >= '0' && s1[i] <= '9'){
                    ++i;                
                }
                //skip - at the end of string
                if (s1[i] == '-' || temp >= s1[i]){
                    ++i;
                }
                s2[j++] = temp++;
            }  
        }
        else{
            s2[j++] = temp;
        }
    }
    s2[j] = '\0';
}