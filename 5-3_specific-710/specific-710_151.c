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
    node *temp = NULL;
    
    ifp = fopen("para.txt", "r");
    if (ifp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(ifp, "%19s", newword) == 1) {
        node* new_node = (node*)malloc(sizeof(node));
        if (new_node == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        
        strcpy(new_node->word, newword);
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            temp = head;
        } else {
            temp->next = new_node;
            temp = temp->next;
        }
    }

    fclose(ifp);

    // Print the linked list
    temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->word);
        temp = temp->next;
    }

    // Free the memory allocated for the linked list
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
