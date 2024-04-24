#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *name;
    int m1;
    struct node *next;
};

struct node *head = NULL; // start with NULL list

void addRecord(const char *pName, int m1) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node)); // allocate node

    int nameLength = strlen(pName);
    newNode->name = (char *)malloc(nameLength + 1); // need space for null terminator
    strcpy(newNode->name, pName);

    newNode->m1 = m1;
    newNode->next = head; // link the old list off the new node
    head = newNode;
}

void clear(void) {
    struct node *current = head;
    struct node *next;

    while (current != NULL) {
        next = current->next; // note the next pointer
        
        free(current->name); // free the allocated name
        free(current); // delete the node

        current = next; // advance to the next node
    }
    head = NULL;
}

int main() {
    // Example usage
    addRecord("Alice", 25);
    addRecord("Bob", 30);

    clear(); // Free allocated memory

    return 0;
}
