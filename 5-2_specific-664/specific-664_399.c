#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t size = 100;
    int* ptr = (int*)malloc(size * sizeof(int));
    
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
    } else {
        // Memory allocation successful, use ptr
        free(ptr); // Don't forget to free the memory when done
    }
    
    return 0;
}
