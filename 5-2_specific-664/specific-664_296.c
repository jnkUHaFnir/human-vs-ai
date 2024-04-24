#include <stdio.h>

struct mystruct {
    struct mystruct* next;
    int data;
};

int main() {
    struct mystruct* ptr = // initialize your pointer here;

    // Use inline assembly to load the address before the load instruction
    struct mystruct* next_ptr;
    asm ("mov %[ptr], %[next_ptr]" : [next_ptr] "=r" (next_ptr) : [ptr] "r" (ptr));
    
    // Use the "next_ptr" variable instead of "ptr" for dereferencing
    // For example, replace mystruct = mystruct->next with next_ptr = next_ptr->next

    // Example usage
    printf("Data: %d\n", next_ptr->data);

    return 0;
}
