#include <stdlib.h>
#include <stdio.h>

int main() {
    int* ptr = malloc(sizeof(int));
    
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    *ptr = 10;
    printf("Value: %d\n", *ptr);
    
    free(ptr);
    
    return 0;
}

When you run your program compiled with AddressSanitizer, it will detect various memory errors, such as use-after-free, double-free, buffer overflow, and memory leaks.

By using tools like AddressSanitizer, you can identify and fix memory errors in your code that may be causing the random segmentation faults on Windows.
