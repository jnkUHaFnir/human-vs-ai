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
    node *head = NULL, *tail = NULL;

    ifp = fopen("para.txt", "r");
    if (ifp == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    while (fscanf(ifp, "%s", newword) != EOF) {
        // Allocate memory for the new node and set the next pointer to NULL
        node *new_node = (node *) malloc(sizeof(node));
        new_node->next = NULL;

        // Copy the word into the new node
        strncpy(new_node->word, newword, 19);
        new_node->word[19] = '\0';

        // If the list is empty, make the new node the head and tail
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            // Otherwise, add the new node to the end of the list and update the tail
            tail->next = new_node;
            tail = new_node;
        }
    }

    // Print the words in the linked list to verify if it was built correctly
    node *current = head;
    while (current) {
        printf("%s\n", current->word);
        current = current->next;
    }

    // Don't forget to close the file
    fclose(ifp);

    // Free the allocated memory for nodes in the linked list
    current = head;
    while (current) {
        node *tmp = current;
        current = current->next;
        free(tmp);
    }

    return 0;
}
