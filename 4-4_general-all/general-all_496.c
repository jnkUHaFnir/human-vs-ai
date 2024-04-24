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
    int x;
    current = (list*)malloc(sizeof(list));
    printf("Enter data: ");
    scanf("%d", &current->data);

    current->next = NULL;
    current->prev = NULL;
    head = current;

    printf("Do you want to enter more (1/0): ");
    scanf("%d", &x);
    
    while (x == 1) {
        current->next = (list*)malloc(sizeof(list));
        current->next->prev = current; // Fix the assignment here
        printf("Enter data: ");
        scanf("%d", &current->next->data);
        
        current->next->next = NULL;
        current = current->next;
        
        end = current;
        printf("Do you want to enter more (1/0): ");
        scanf("%d", &x);
    }

    newn = head;
    while (newn != NULL) {
        printf("%d:%d:%d->", newn->prev, newn->data, newn->next->data);
        newn = newn->next;
    }
    
    printf("\nTraversing from tail to head:\n");
    while (end != NULL) {
        printf("%d ", end->data);
        end = end->prev;
    }
    
    return 0;
}
