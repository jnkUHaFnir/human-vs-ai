#include <stdio.h>
#include <stdlib.h>

struct Node {
    int index;
    struct Node* next;
};

void addIndex(struct Node** head, int index) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->index = index;
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->index);
        current = current->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct Node* indexes = NULL;
    
    // Example usage
    addIndex(&indexes, 4);
    addIndex(&indexes, 7);
    addIndex(&indexes, 2);
    
    printList(indexes);
    
    freeList(indexes);
    
    return 0;
}
