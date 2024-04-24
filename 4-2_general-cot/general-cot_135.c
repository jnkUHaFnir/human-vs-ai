#include <stdlib.h>
#include <string.h>

struct node {
    char* name;
    int m1;
    struct node* next;
};

struct node* head = NULL; // Start with NULL list

void addRecord(const char* pName, int ms1) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node)); // Allocate node

    int nameLength = strlen(pName);
    newNode->name = (char*)malloc(nameLength + 1); // +1 for null terminator
    strcpy(newNode->name, pName);

    newNode->m1 = ms1;
    newNode->next = head; // Link the old list off the new node
    head = newNode;
}

void clear(void) {
    struct node* current = head;
    struct node* next;
    while (current != NULL) {
        next = current->next; // Note the next pointer

        if (current->name != NULL) {
            free(current->name);
        }

        free(current); // Delete the node
        current = next; // Advance to the next node
    }
    head = NULL;
}
