#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char word[20];
    struct node *next;
} node;

int main() {
    FILE *ifp;
    char newword[20];
    node *head = NULL;
    node *current = NULL;

    ifp = fopen("para.txt", "r");

    if (ifp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fscanf(ifp, "%19s", newword) == 1) {
        node *newNode = (node *)malloc(sizeof(node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        strcpy(newNode->word, newword);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    fclose(ifp);

    // Traverse the linked list
    current = head;
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
