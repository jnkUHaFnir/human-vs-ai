#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char word[20];
    struct node *next;
} node;

int main() {
    FILE *ifp;
    char newword[20];
    node *head = NULL, *current = NULL, *newnode = NULL;

    ifp = fopen("para.txt", "r");
    if (ifp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fscanf(ifp, "%19s", newword) != EOF) {
        // Allocate a new node
        newnode = (node *)malloc(sizeof(node));
        if (newnode == NULL) {
            perror("Error allocating memory");
            return 1;
        }

        // Copy the word to the new node
        strcpy(newnode->word, newword);
        newnode->next = NULL;

        // If the list is empty, this is the new head
        if (head == NULL) {
            head = newnode;
        } else {
            // Otherwise, append to the end of the list
            current->next = newnode;
        }

        // Move the current node forward
        current = newnode;
    }

    fclose(ifp); // Close the file

    /* Printing and freeing the list for demonstration */
    current = head; // Start from the head of the list
    while (current != NULL) {
        printf("%s\n", current->word); // Print the word
        
        // Free the memory and move to the next node
        node *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
