#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define FALSE 0
#define TRUE  1

struct linkedStruct {
    int elem;
    struct linkedStruct* next;
};

typedef struct linkedStruct linked;
typedef linked* linkedPtr;

void push(linkedPtr* hd, int val) {
    linkedPtr ptr = (linkedPtr)malloc(sizeof(linked));
    ptr->elem = val;
    ptr->next = *hd;
    *hd = ptr;
}

int isEmpty(linkedPtr hd) {
    return hd == NULL ? TRUE : FALSE;
}

int top(linkedPtr hd) {
    return hd->elem;
}

void pop(linkedPtr* hd) {
    if (*hd == NULL) {
        return; // Stack is already empty
    }
    linkedPtr tmp = *hd;
    *hd = (*hd)->next;
    free(tmp);
}

void show(linkedPtr hd) {
    while (hd != NULL) {
        printf("%d, ", hd->elem);
        hd = hd->next;
    }
    printf("\n");
}

int main(int argc, char** argv) {
    linkedPtr head = NULL;
    int i;
    int temp;

    for (i = 0; i < SIZE; ++i) {
        temp = rand() % 100;
        printf("In main(): temp: %6d\n", temp);
        push(&head, temp);
        show(head);
    }

    printf("\n");

    while (!isEmpty(head)) {
        printf("Top of stack value is: %d\n", top(head));
        pop(&head);
    }

    return 0;
}
