#include <stdlib.h>
#include <stdio.h>

#define HASHTABLE_SIZE 11

typedef struct node {
    int value;
    struct node* next;
} node;

// This is the hash_function
int get_location(int key)
{
    if(key < 0) {
        key *= -1;
    }
    // unsigned long hash = 0;
    // int c;

    // while((c = key++) != '\0') {
    //     hash = c + (hash << 6) + (hash << 16) - hash;
    // }
    return key % HASHTABLE_SIZE;
}

void insert_new_node(node** head, int new_value){
    node* new_node = malloc(sizeof(node*));
    new_node->value = new_value;
    new_node->next = NULL;

    if(*head == NULL) {
        *head = new_node;
    } else {
        node* current = *head;

        // while we dont hit the tail lets look for it
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void insert_table(node** hashtable, int new_value) 
{
    int location = get_location(new_value);
    if(hashtable[location] == NULL) {
        hashtable[location] = malloc(sizeof(node*));

        node* head = NULL;
        insert_new_node(&head, new_value);

        hashtable[location] = head;
    } else {
        node* head = hashtable[location];
        insert_new_node(&head, new_value);

        hashtable[location] = head;
    }
}


node** get_hashTable() 
{
    node** hashTable = calloc(HASHTABLE_SIZE, sizeof(node**));
    return hashTable;
}

void display_table(node** hashtable) 
{
    for(int i = 0; i < HASHTABLE_SIZE; i++) {
        node* head = hashtable[i];

        printf("%d: ", i);

        if(head == NULL) {
            printf("NULL");
        } else {
            node* current = head;

            while(current != NULL) {
                printf("%d ", current->value);
                current = current->next;
            }
        }
        printf("\n"); 
    }
}

int main(int argc, char* argv[]) {
    node** table = get_hashTable();

    insert_table(table, 0);
    insert_table(table, 2);
    insert_table(table, 78);
    insert_table(table, 12);
    insert_table(table, 9);
    insert_table(table, 6);

    insert_table(table, 4);
    insert_table(table, 1);
    insert_table(table, 5);
    insert_table(table, 9);
    insert_table(table, 10);
    insert_table(table, 11);

    insert_table(table, -30);
    insert_table(table, 8);
    insert_table(table, 8);
    insert_table(table, 4);
    insert_table(table, 9);
    insert_table(table, 5);

    display_table(table);

    return 0;
    // node* head = NULL;
    // insert_new_node(&head, 5);
    // insert_new_node(&head,6);

    // printf("%d\n", head->value);
    // printf("%d\n", head->next->value);
    // segmentation fault
    // printf("%d\n", head->next->next->value);

}



