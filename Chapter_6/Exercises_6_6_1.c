#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/*
Implement a simple version of #define processor (i.e no arguments)
suitable for use with C programs, based on the routine of this section.
You may also find getch and ungetch helpful
*/

#define HASHSIZE 101
#define BUFSIZE 100
#define MAXWORD 100

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtable[HASHSIZE];

unsigned hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
void undef(char *);
int getword(char *, int);
void error(int , char*);
void getdef(void);
void skipblanks(void);
void ungets(char *);


int main(int argc, char *argv[]){

    char word[MAXWORD];
    struct nlist *p;

    while (getword(word, MAXWORD) != EOF){
        if (strcmp(word, "#") == 0){
            getdef();
        }
        else if (!isalpha(word[0])){
            printf("cannot be identify: %s\n", word);
        }
        else if ((p = lookup(word)) == NULL){
            printf("not identified in hash table: %s\n", word);
        }
        else{
            ungets(p->defn);
        }
    }
    return 0;
}

char *str_up(char *w){
    char *p;
    p = (char *)malloc(sizeof(strlen(w) + 1));

    if (p != NULL){
        strcpy(p, w);
    }
    return p;
}

/* hash: form hash value from string s */ 
unsigned hash(char *s){
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++){
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

/*lookup: look for s in hashtab */
struct nlist *lookup(char *s){
    struct nlist *np;

    for (np = hashtable[hash(s)]; np != NULL; np = np->next){
        if (strcmp(s, np->name) == 0){
            return np;
        }
    }
    return NULL;
}

/*install: put(name, defn) in hashtab */
struct nlist *install(char *name, char *defn){

    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL){
        np = (struct nlist *)malloc(sizeof(np));
        if (np == NULL || ((np->name) = str_up(name)) == NULL){
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtable[hashval];
        hashtable[hashval] = np;
    }
    else{
        free((void *) np->defn);
    }
    if ((np->defn = str_up(defn)) == NULL){
        return NULL;
    }
    return np;
}

/*undef: remove a name and definition from the table */
void undef(char *s){
    int h;
    struct nlist *prev, *np;

    h = hash(s);

    for (np = hashtable[h]; np != NULL; np = np->next){
        if (strcmp(s, np->name) == 0){
            break;
        }
        prev = np;
    }
    if (np != NULL){
        if (prev == NULL){
            hashtable[h] = np->next;
        }
        else{
            prev->next = np->next;
        }
        free((void *) np->name);
        free((void *) np->defn);
        free((void *) np);
    } 
}

int buf_pos = 0;
char buffer[BUFSIZE];

int getch(void){
    return (buf_pos > 0)? buffer[--buf_pos] : getchar();
}

void ungetch(int c){
    if (buf_pos >= BUFSIZE){
        printf("ungetch: There are too many characters\n");
    }
    else{
        buffer[buf_pos++] = c;
    }
}

int comment(void){
    int input;

    while ((input = getch()) != EOF){
        if (input == '*'){
            if ((input = getch()) == '/'){
                break;
            }
        }
        else{
            ungetch(input);
        }
    }
    return input;
}

int getword(char *word, int lim){
    int input, input2;
    char *w = word;

    while (isspace(input = getch()) && input != '\n'){
        ;
    }

    if (input != EOF){
        *w++ = input;
    }

    if (isalpha(input) || input == '-' || input == '#'){
        for ( ; --lim > 0; w++){
            if (!isalnum(*w = getch()) && *w != '-'){
                ungetch(*w);
                break;
            }
        }
    }
    else if(input == '\'' || input == '"'){
        for ( ; --lim > 0; w++){
            if ((*w = getch()) == '\\'){
                *w++ = getch();
            }
            else if (*w == input){
                w++;
                break;
            }
            else if(*w == EOF){
                break;
            }
        }
    }
    else if (input == '/'){
        if ((input2 = getch()) == '*'){
            input = comment();
        }
        else{
            ungetch(input2);
        }
    }
    *w = '\0';
    return input;
}

void error(int c, char *error_msg){

    printf("%d, %s\n", c, error_msg);
    while (c != EOF && c != '\n'){
        c = getch();
    }
}

void getdef(void){

    int input, i;
    char def[MAXWORD], name[MAXWORD], dir[MAXWORD];

    skipblanks();
    if (!isalpha(getword(dir, MAXWORD))){
        error(dir[0], "getdef: expecting a directive after #");
    }
    else if (strcmp(dir, "define") == 0){
        skipblanks();
        if (!isalpha(getword(name, MAXWORD))){
            error(name[0], "getdef: non-alpha - name expected");
        }
        else{
            skipblanks();
            for (i = 0; i < MAXWORD - 1; i++){
                printf("here %d\n", i);
                if ((def[i] = getch()) == EOF || def[i] == '\n'){
                     printf("name %c\n", def[i]);
                    break;
                }
            }
            printf("here i1: %d\n", i);
            def[i] = '\0';
            if ( i <= 0 ){
                error('\n', "getdef: incomplete define");
            }
            else{
                install(name, def);
            }
        }
    }
    else if (strcmp(dir, "undef") == 0){
        skipblanks();
        if (!isalpha(getword(name, MAXWORD))){
            error(name[0], "getdef: non-alpha in undef");
        }
        else{
            undef(name);
        }
    }
    else{
        error(dir[0], "getdef: expecting a directive after #");
    }
}

void skipblanks(void){
    int input;

    while ((input = getch()) == ' ' || input == '\t'){
        ;
    }
    ungetch(input);
}

void ungets(char *s){
    int i;

    for (i = strlen(s) - 1; i >= 0; --i){
        ungetch(s[i]);
    }
}
