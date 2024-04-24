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
    node *head = NULL;
    node *current = NULL;

    ifp = fopen("para.txt", "r");

    if (ifp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fscanf(ifp, "%s", newword) != EOF) {
        if (head == NULL) {
            head = (node *)malloc(sizeof(node));
            strcpy(head->word, newword);
            head->next = NULL;
            current = head;
        } 
        else {
            current->next = (node *)malloc(sizeof(node));
            current = current->next;
            strcpy(current->word, newword);
            current->next = NULL;
        }
    }

    fclose(ifp);

    // Print the linked list
    current = head;
    while (current != NULL) {
        printf("%s ", current->word);
        current = current->next;
    }

    // Free the memory
    current = head;
    while (current != NULL) {
        node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
