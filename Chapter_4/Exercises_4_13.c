 #include <stdio.h>
 #include <string.h>
 

 /*Write a recursive version of the function reverse(s) */
 void reverse(char s[], int i, int len);

 int main(){

     char s[] = "hello";
     int len = strlen(s);
     printf("Original string: %s\n", s);
     reverse(s, 0, len);
     printf("Reverse string: %s\n", s);
     
 }

 /*reverse the string in place */
 void reverse(char s[], int i, int len){
    int temp, j;
    j = len - 1;

    if (i < j){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        reverse(s, ++i, --len);
    }
 }