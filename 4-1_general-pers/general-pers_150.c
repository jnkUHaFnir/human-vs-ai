#include <stdlib.h>

float * foo = NULL;

void update(int a)
{
    float * new_foo = (float *)malloc(a * 2 * sizeof(float));
    
    if (new_foo == NULL) {
        // Handle memory allocation failure
    }
    
    // Copy data, if needed, from foo to new_foo
    
    free(foo); // Free the old memory
    
    foo = new_foo; // Update foo to point to the new memory location
}

int main() {
    int a = 10; // example value
    
    update(a);
    
    // Use the memory allocated in foo
    
    // Free the memory when it is no longer needed
    if (foo != NULL) {
        free(foo);
        foo = NULL; // Reset pointer to avoid dangling pointer
    }
    
    return 0;
}
