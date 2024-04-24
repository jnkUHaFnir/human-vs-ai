#include <stdio.h>

typedef struct Node {
    struct Node* next;
    int data;
} Node;

int main() {
    Node* mystruc = malloc(sizeof(Node));
    mystruc->data = 10;
    
    Node** nextPtr = &(mystruc->next);
    Node* nextValue;

    asm volatile("movq (%1),%0" : "=r" (nextValue) : "r" (nextPtr));

    printf("Next node data: %d\n", nextValue->data);

    return 0;
}
