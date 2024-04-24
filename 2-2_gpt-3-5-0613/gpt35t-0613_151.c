#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Added for string functions

typedef struct node {
    char word[20];
    struct node* next;
} node;

int main() {
    FILE* ifp;
    char newword[20];
    node* head = NULL; // Initialize head to NULL

    ifp = fopen("para.txt", "r");

    // Check if the file opened successfully
    if (ifp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(ifp, "%s", newword) != EOF) {
        // Create a new node
        node* newNode = (node*)malloc(sizeof(node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        // Copy the word to the node's "word" field
        strcpy(newNode->word, newword);

        // Link the new node to the list
        newNode->next = head;
        head = newNode;
    }

    // Close the file
    fclose(ifp);

    // Traverse the linked list and print the words
    node* current = head;
    while (current != NULL) {
        printf("%s ", current->word);
        current = current->next;
    }

    // Free the memory allocated for the linked list
    current = head;
    while (current != NULL) {
        node* temp = current; // Save the current node
        current = current->next;
        free(temp); // Free the saved node
    }

    return 0;
}
