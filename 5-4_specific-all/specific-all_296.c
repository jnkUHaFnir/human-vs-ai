#include <stdint.h>

struct Node {
    struct Node* next;
    // other fields
};

void* capture_address(struct Node *node) {
    void *captured_address;
    
    asm volatile(
        "lea (%1), %0" // Load effective address of node->next into %0
        : "=r" (captured_address)
        : "r" (&node->next)
    );

    return captured_address;
}

int main() {
    struct Node *mystruc = /* initialize your struct here */;

    void *captured_addr = capture_address(mystruc);
    
    // Use the captured address for analysis before any problematic load operation
    
    mystruc = mystruc->next; // This load operation might mess with the address, so use the captured address instead
    
    // Continue with your program
    return 0;
}
