#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node list;

list *head, *current, *newn, *end;

int main() {
    int x, y;
    current = (list*)malloc(sizeof(list));
    printf("enter data:");
    scanf("%d", &current->data);

    current->next = NULL;
    current->prev = NULL;
    head = current;
    printf("do you want to enter more:");
    scanf("%d", &x);
    while (x == 1) {
        current->next = (list*)malloc(sizeof(list));
        printf("enter data:");
        scanf("%d", &current->next->data);
        current->next->prev = current; // Set the previous node correctly
        current->next->next = NULL;
        current = current->next;
        end = current;
        printf("do you want to enter more:");
        scanf("%d", &x);
    }

    // Traversing from head to tail
    newn = head;
    while (newn != NULL) {
        printf("%p:%d:%p->", newn->prev, newn->data, newn->next);
        newn = newn->next;
    }

    // Traversing from tail to head
    while (end != NULL) { // Modified loop condition
        printf("%d", end->data);
        end = end->prev;
    }
    
    // Free allocated memory
    newn = head;
    while (newn != NULL) {
        list* temp = newn;
        newn = newn->next;
        free(temp);
    }

    return 0;
}
