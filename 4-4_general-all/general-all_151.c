#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char word[20];
    struct node* next;
} node;

int main() {
    FILE* ifp;
    char newword[20];
    node* head = NULL;
    node* current = NULL;

    ifp = fopen("para.txt", "r");
    if (ifp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the first word separately
    if (fscanf(ifp, "%s", newword) != EOF) {
        head = (node*)malloc(sizeof(node));
        if (head == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        strcpy(head->word, newword);
        head->next = NULL;
        current = head;
    }

    // Continue reading the rest of the file
    while (fscanf(ifp, "%s", newword) != EOF) {
        current->next = (node*)malloc(sizeof(node));
        if (current->next == NULL) {
            printf("Memory allocation failed.\n");
            // Clean up allocated memory before exiting on error
            while (head != NULL) {
                node* temp = head;
                head = head->next;
                free(temp);
            }
            fclose(ifp);
            return 1;
        }
        current = current->next;
        strcpy(current->word, newword);
        current->next = NULL;
    }

    // Close the file
    fclose(ifp);

    // Print the words in the linked list
    current = head;
    while (current != NULL) {
        printf("%s\n", current->word);
        current = current->next;
    }

    // Free the allocated memory
    current = head;
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
