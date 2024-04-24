#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char word[20];
    struct node* next;
} node;

int main() {
    FILE *ifp;
    char newword[20];
    node *head = NULL; // Initialize head to NULL

    ifp = fopen("para.txt", "r");
    if (ifp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    head = (node*)malloc(sizeof(node));
    node* current = head; // Current pointer to traverse the linked list

    while (fscanf(ifp, "%s", newword) == 1) {
        node* newnode = (node*)malloc(sizeof(node));
        if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        
        strcpy(newnode->word, newword);
        newnode->next = NULL;

        current->next = newnode;
        current = current->next;
    }

    // Close the file
    fclose(ifp);

    // Print the words in the linked list
    current = head->next; // Skip the dummy head node
    while (current != NULL) {
        printf("%s\n", current->word);
        current = current->next;
    }

    // Free dynamically allocated memory
    current = head;
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
