#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/*
Write a function undef that will remove a name and definition from the table
maintained by lookup and install
*/

#define HASHSIZE 101

struct nlist {                  // table entry:
    struct nlist *next;         // next entry in chain
    char *name;                 // defined name
    char *defn;                 // replacement text
};

// pointer table
static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *);
struct nlist *install(char *, char *);
struct nlist *lookup(char *);
void undef(char *);

int main(){

    printf("hash(\"IN\") == 18? : %d\n", hash("IN") == 18);
    struct nlist *p = lookup("IN");
    printf("lookup(\"IN\") == NULL? : %d\n", p == NULL);
    p = install("IN", "TEXT");
    printf("install(\"IN\", \"TEXT\") == NULL? : %d\n", p == NULL);
    p = lookup("IN");
    printf("lookup(\"IN\") == NULL? : %d\n", p == NULL);
    undef(p->name);
    printf("undef(\"IN\")\n");
    p = lookup("IN");
    printf("lookup(\"IN\") == NULL? : %d\n", p == NULL);

    return 0;

}

/*undef: remove a name and definition from the table */
void undef(char *s){
    int h;
    struct nlist *prev, *np;

    h = hash(s);
    for (np = hashtab[h]; np != NULL; np = np->next){
        if (strcmp(s, np->name) == 0){          // both are identical 
            break;
        }
        prev = np;              // remenber the last one
    }
    if (np != NULL){            // found name
        if (prev == NULL){      // first in the hash table?
            hashtab[h] = np->next;
        }
        else{                   //  elsewhere in the hash list
            prev->next = np->next;
        }
        free((void *) np->name);
        free((void *) np->defn);
        free((void *) np);
    }
}


/*lookup: searchs for s in the table, ad returns a pointer to the place
where it was found, or NULL if it wasn't there 
lookup: look for s in hashtab */
struct nlist *lookup(char *s){
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next){
        if (strcmp(s, np->name) == 0){
            return np;                  // found
        }
    }
    return NULL;                        // not found
}

char *strd_up(char *w){
    char *p;
    p = (char *)malloc(strlen(w) + 1);

    if (p != NULL){
        strcpy(p, w);
    }
    return p;
}

/*install: records the name s and the replacement text t in a table 
install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn){
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL){         // not found
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL || (np->name = strd_up(name)) == NULL){
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else{                                   // already there
        free((void *) np->defn);            // free previous define
    }
    if ((np->defn = strd_up(defn)) == NULL){
        return NULL;
    }
    return np;
}

/* 
adds each character value in the string to a scrambled combination of 
the previous ones and returns the remainder modulo the array size.
*/
/* hash: form hash value for string s */
unsigned hash(char *s){
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++){
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

