#include <stdio.h>

// Struct representing your linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to access the next pointer while recording the address before it gets overwritten
struct Node* getNextAndUpdate(struct Node* current) {
    struct Node* next = current->next; // Record the address before it gets overwritten
    // Do anything else you need with the addresses
    printf("Accessing next at address: %p\n", next);
    return next;
}

int main() {
    struct Node* head = NULL;
    
    // Create a linked list for demonstration
    struct Node n1, n2, n3;
    n1.data = 1; n2.data = 2; n3.data = 3;
    n1.next = &n2; n2.next = &n3; n3.next = NULL;
    head = &n1;

    struct Node* current = head;
    while (current != NULL) {
        // Process current node
        printf("Accessing data at address: %p\n", &(current->data));
        
        // Update current node using our custom function
        current = getNextAndUpdate(current);

        // You can do other operations here before moving to the next node
    }

    return 0;
}
