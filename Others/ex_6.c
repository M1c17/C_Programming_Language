#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NKEYS (sizeof keytab / sizeof keytab[0])
#define MAXWORD 100

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "do", 0,
    "double", 0,
    "else", 0,
    "enum", 0,
    "extern", 0,
    "float", 0,
    "for", 0,
    "goto", 0,
    "if", 0,
    "int", 0,
    "long", 0,
    "register", 0,
    "return", 0,
    "short", 0,
    "signed", 0,
    "sizeof", 0,
    "static", 0,
    "struct", 0,
    "switch", 0,
    "typedef", 0,
    "union", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

void parser();
void countWord(char *);
void print();

int main() {
    parser();
    print();
    return 0;
}


void parser() {
    char word[100];
    char *input = word;
    while ((*input = getchar()) != EOF) {
        if (*input == ' ' || *input == '\n' || *input == '\t') {
            *input = '\0';
            countWord(word);
            input = word;
        } else {
            input++;
        }
    }
}

void countWord(char *word) {
    int i = 0;
    for (i = 0; i < NKEYS; i++) {
        char *word2 = keytab[i].word;
        if (strcmp(word, word2) == 0) {
            keytab[i].count += 1;
        }
    }
}

void print() {
    int i = 0;
    for (i = 0; i < NKEYS; i++) {
        printf("key %s value %d \n", keytab[i].word, keytab[i].count);
    }
}