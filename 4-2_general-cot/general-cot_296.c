#include <stdio.h>
#include <stdint.h>

typedef struct Node {
    struct Node* next;
    int data;
} Node;

int main() {
    Node* mystruct = (Node*)malloc(sizeof(Node));
    mystruct->data = 10;

    Node* nextNode = mystruct->next; // Load the address before access

    // Access data without relying on PEBS to capture the address
    if(nextNode != NULL) {
        printf("Next node data: %d\n", nextNode->data);
    }

    return 0;
}
