#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char* name;
    int m1;
    struct node* next;
};

struct node* head = NULL;

void addRecord(const char* pName, int ms1)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node)); // allocate node

    int nameLength = strlen(pName);
    newNode->name = (char*)malloc(nameLength + 1); // allocate memory for name and include space for null terminator
    strcpy(newNode->name, pName);

    newNode->m1 = ms1;
    newNode->next = head; // link the old list off the new node
    head = newNode;
}

void clear(void)
{
    struct node* current = head;
    struct node* next;
    while (current != NULL) {
        next = current->next;
        if (current->name != NULL) {
            free(current->name); // free the memory allocated for name
        }
        free(current); // delete the node
        current = next; // advance to the next node
    }
    head = NULL;
}
