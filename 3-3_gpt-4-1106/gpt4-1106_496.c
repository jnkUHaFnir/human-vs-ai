current->next->prev = current->next; // This is incorrect
current->next->prev = current; // This is the correct assignment
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

        current->next->prev = current; // Corrected line
        current->next->next = NULL;

        current = current->next;
        end = current;
        printf("do you want to enter more:");
        scanf("%d", &x);
    }

    newn = head;
    printf("Traversal Head to Tail:\n");
    while (newn != NULL) {
        printf("%d -> ", newn->data);
        newn = newn->next;
    }
    printf("NULL\n");

    printf("Traversal Tail to Head:\n");
    while (end != NULL) {
        printf("%d -> ", end->data);
        end = end->prev;
    }
    printf("NULL\n");

    return 0;
}
