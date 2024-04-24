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
        current->next->prev = current;
        current->next->next = NULL;
        
        printf("enter data:");
        scanf("%d", &current->next->data);

        current = current->next;
        end = current;
        
        printf("do you want to enter more:");
        scanf("%d", &x);
    }

    newn = head;
    while (newn != NULL) {
        printf("%d:%d:%d->", newn->prev, newn->data, newn->next);
        newn = newn->next;
    }
    
    while (end != NULL) {
        printf("%d", end->data);
        end = end->prev;
    }

    return 0;
}
