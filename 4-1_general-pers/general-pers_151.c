#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct node {
    char word[MAX_WORD_LENGTH];
    struct node *next;
} node;

int main() {
    FILE *ifp;
    char newword[MAX_WORD_LENGTH];
    node *head = NULL;
    node *current = NULL;

    ifp = fopen("para.txt", "r");
    if (ifp == NULL) {
        perror("Error opening file");
        return 1;
    }

    head = (node *)malloc(sizeof(node));
    if (head == NULL) {
        perror("Memory allocation failed");
        return 1;
    }
    head->next = NULL;
    current = head;

    while (fscanf(ifp, "%s", newword) == 1) {
        node *newNode = (node *)malloc(sizeof(node));
        if (newNode == NULL) {
            perror("Memory allocation failed");
            return 1;
        }
        strncpy(newNode->word, newword, MAX_WORD_LENGTH);
        newNode->next = NULL;
        
        current->next = newNode;
        current = newNode;
    }

    fclose(ifp);

    // Print the linked list for verification
    current = head->next;
    while (current != NULL) {
        printf("%s\n", current->word);
        current = current->next;
    }

    // Free allocated memory
    current = head;
    while (current != NULL) {
        node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
