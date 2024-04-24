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
    node *head = NULL;
    node *current = NULL;
    
    ifp = fopen("para.txt", "r");
    if (ifp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(newword, sizeof(newword), ifp)) {
        node *newNode = (node *)malloc(sizeof(node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        
        // Remove newline character if present
        newword[strcspn(newword, "\n")] = 0;
        
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

    // Print the words in the linked list
    node *temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->word);
        temp = temp->next;
    }

    // Free dynamically allocated memory
    while (head != NULL) {
        node *temp = head;
        head = head->next;
        free(temp);
    }

    fclose(ifp);
    return 0;
}
