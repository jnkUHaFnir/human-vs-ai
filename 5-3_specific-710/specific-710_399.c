#include <stdio.h>
#include <malloc.h> // For _aligned_malloc

int main() {
    const size_t num_elements = 10;
    const size_t align_size = 16; // Example alignment size

    // Allocate memory aligned to a 16-byte boundary for an array of integers
    int* aligned_memory = (int*)_aligned_malloc(num_elements * sizeof(int), align_size);

    if (aligned_memory != NULL) {
        // Memory allocation successful, use aligned_memory as needed
        
        // Don't forget to free the memory when done
        _aligned_free(aligned_memory);
    } else {
        printf("Failed to allocate memory.\n");
    }

    return 0;
}
