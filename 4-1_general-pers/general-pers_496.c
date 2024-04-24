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
    head = NULL;
    end = NULL;

    // Input data
    do {
        current = (list*)malloc(sizeof(list));
        printf("Enter data: ");
        scanf("%d", &current->data);
        current->next = NULL;
        current->prev = end;

        if (end != NULL) {
            end->next = current;
        }

        end = current;

        if (head == NULL) {
            head = current;
        }

        printf("Do you want to enter more (1 for yes, 0 for no): ");
        scanf("%d", &x);
    } while (x == 1);

    // Traverse from head to tail
    printf("Traversal from head to tail:\n");
    newn = head;
    while (newn != NULL) {
        printf("%d -> ", newn->data);
        newn = newn->next;
    }

    // Traverse from tail to head
    printf("\nTraversal from tail to head:\n");
    newn = end;
    while (newn != NULL) {
        printf("%d -> ", newn->data);
        newn = newn->prev;
    }

    // Free memory of nodes
    newn = head;
    while (newn != NULL) {
        current = newn;
        newn = newn->next;
        free(current);
    }

    return 0;
}
