#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define HASH_SIZE 20000

typedef struct entry_t {
    char *key;
    char *value;
    struct entry_t *next;
} entry_t;

// hashtable
typedef struct ht_t{
    entry_t **entries;
} ht_t;

ht_t *ht_create(void) {
    // allocate table
    ht_t *hashtable = malloc(sizeof(ht_t) * 1);

    // allocate table entries
    hashtable->entries = malloc(sizeof(entry_t *)* HASH_SIZE);

    // set each to null (needed for proper operation)
    for(int i = 0; i < HASH_SIZE; i++) {
        hashtable->entries[i] = NULL;
    }

    return hashtable;
}

unsigned long hash_function(const char *key)
{
    unsigned long hash = 0;
    int c;

    while((c = *key++) != '\0') {
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    return (hash % HASH_SIZE);
}

entry_t *ht_pair(const char *key, const char *value) {
    //allocate the entry
    entry_t *entry = malloc(sizeof(entry_t) * 1);
    entry->key = malloc(strlen(key) + 1);
    entry->value = malloc(strlen(value) + 1);

    // copy the key and the value in place
    strcpy(entry->key, key);
    strcpy(entry->value, value);

    // next starts out null but may be set later on
    entry->next = NULL;

    return entry;
}

// insert into hashtable
void ht_insert(ht_t *hastable, const char *key, char *value) {
    unsigned long slot = hash_function(key);

    // try to look up an entry set
    entry_t *entry = hastable->entries[slot];
    //printf("here at the begining\n");

    // no entry means bucket empty , insert inmediately
    if(entry == NULL) {
        hastable->entries[slot] = ht_pair(key, value);
        return;
    }
    entry_t *prev;

    // walk through each entry until either the end is reached or a
    // matching key is found
    while (entry != NULL) {
        // check key
        if(strcmp(entry->key, key) == 0) {
            // match found, replace value
            free(entry->value);
            entry->value = malloc(strlen(value) + 1);
            strcpy(entry->value, value);
            return;
        }

        // walk to next
        prev = entry;
        entry = prev->next;
    }
    // end of chain reached without a match, add new
    prev->next = ht_pair(key, value);
}

char *ht_get(ht_t *hashtable, const char *key) {
    unsigned int slot = hash_function(key);

    // try to find a valid slot
    entry_t *entry = hashtable->entries[slot];

    // no slot means no entry
    if(entry == NULL) {
        return NULL;
    }

    // walk through each entry in the slot
    while(entry != NULL) {
        if(strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        // proceed to next key if available
        entry = entry->next;
    }
    return NULL;
}

void ht_del(ht_t *hashtable, const char * key) {
    unsigned int bucket = hash_function(key);

    // try to find a valid bucket
    entry_t *entry = hashtable->entries[bucket];

    // no bucket = no entry
    if (entry == NULL) {
        return;
    }

    entry_t *prev;
    int idx = 0;

    // walk through each entry until either the end is reached or a matching key is found
    while (entry != NULL) {
        // check key
        if (strcmp(entry->key, key) == 0) {
            //first item and no next entry
            if(entry->next == NULL && idx == 0) {
                hashtable->entries[bucket] = NULL;
            }

            // first item with a next entry
            if(entry->next != NULL && idx == 0) {
                hashtable->entries[bucket] = entry->next;
            }

            // last item
            if(entry->next == NULL && idx != 0) {
                prev->next = NULL;
            }

            // middle item
            if(entry->next != NULL && idx != 0) {
                prev->next = entry->next;
            }
            // free the deleted entry
            free(entry->key);
            free(entry->value);
            free(entry);

            return;
        }
        // walk to next
        prev = entry;
        entry = prev->next;
        ++idx;
    }
}

void display_ht(ht_t *hashtable) {
    for(int i = 0; i < HASH_SIZE; ++i) {
        entry_t *entry = hashtable->entries[i];

        if(entry == NULL) {
            continue;
        }

        printf("slot[%4d]: ", i);

        for(;;) {
            printf("%s-%s ", entry->key, entry->value);

            if(entry->next == NULL) {
                break;
            }

            entry = entry->next;
        }

        printf("\n");
    }
}


int main(int argc, char* argv[]) {
    //printf("%llu\n", hash_function("em"));
    ht_t *ht = ht_create();

    ht_insert(ht, "name1", "em");
    ht_insert(ht, "name2", "russian");
    ht_insert(ht, "name3", "pizza");
    ht_insert(ht, "name4", "doge");
    ht_insert(ht, "name5", "pyro");
    ht_insert(ht, "name6", "joost");
    ht_insert(ht, "name7", "kalix");

    display_ht(ht);

    ht_del(ht, "name1");

    display_ht(ht);

    return 0;
}