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
        current->next->prev = current; // Corrected assignment
        current->next->next = NULL;
        current = current->next;
        end = current;
        printf("do yo want to enter more:");
        scanf("%d", &x);
    }

    newn = head;
    while (newn != NULL) {
        printf("%p:%d:%p->", newn->prev, newn->data, newn->next);  // Modified to print the pointers
        newn = newn->next;
    }
    while (end != NULL) {
        printf("%d ", end->data);
        end = end->prev;
    }
    return 0;
}
