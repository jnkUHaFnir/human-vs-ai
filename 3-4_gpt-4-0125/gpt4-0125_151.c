#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Needed for strcpy

typedef struct node {
    char word[20];
    struct node *next;
} node;

int main() {
    FILE *ifp;
    char newword[20];
    node *head = NULL, *tail = NULL, *temp = NULL;

    ifp = fopen("para.txt", "r");
    if (ifp == NULL) {
        perror("Error opening file"); // Provide error feedback
        return 1;
    }

    while (fscanf(ifp, "%s", newword) != EOF) {
        // Create a new node for each word
        temp = (node *)malloc(sizeof(node));
        if (temp == NULL) {
            perror("Failed to allocate memory");
            return 1;
        }

        // Copy the word into the new node
        strcpy(temp->word, newword);
        temp->next = NULL;

        // If the list is empty, this is the new head
        if (head == NULL) {
            head = temp;
        } else {
            // Otherwise, append to the end of the list
            tail->next = temp;
        }

        // Move the tail to point to the last element
        tail = temp;
    }

    // Now let's print the list to verify it's correct
    temp = head; // Start from the head
    printf("List of words:\n");
    while (temp != NULL) {
        printf("%s\n", temp->word);
        temp = temp->next;
    }

    // Free the list
    while (head != NULL) {
        temp = head; // Get the current head
        head = head->next; // Move to the next node
        free(temp); // Free the current head
    }

    fclose(ifp); // Don't forget to close the file!

    return 0;
}
