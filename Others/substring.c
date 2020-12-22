#include <stdio.h>
#include <string.h>

void substring(char *s, char *str);

int main(){

    char str[] = "test";
    char s[] = "xaa";
    substring(s, str);
    printf("%s\n", str);

}

/*substring: get a substring of s and put into string */
void substring(char *s, char *str){
    int i, j, len;
    int pos1 = 1;
    int pos2 = 2; 
    len = strlen(s);
    
    if (pos2 > 0 && len > pos2){
        len = pos2;
    }
    else if (pos2 > 0 && len < pos2){
        printf("Error: string too short\n");
    }
    for (j = 0, i = pos1; i < len; i++, j++){
        str[j] = s[i];
        printf("here: %s\n", str);
    }
    str[j] = '\0';  
}