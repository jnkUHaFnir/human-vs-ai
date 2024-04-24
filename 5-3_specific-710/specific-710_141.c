#include <stdio.h>
#include <string.h>

int all_bytes_are_zero(const unsigned char* array, size_t size) {
    unsigned char* zero_array = malloc(sizeof(unsigned char) * size);
    if (zero_array == NULL) {
        // Handle memory allocation failure
        return -1;
    }
    
    memset(zero_array, 0, size); // Initialize zero_array with zeros
    
    int result = memcmp(array, zero_array, size); // Compare the arrays
    
    free(zero_array); // Free the allocated memory
    
    return result == 0; // If result is 0, all bytes are zero
}

int main() {
    unsigned char test_array[] = {0, 0, 0, 0, 0};
    
    if(all_bytes_are_zero(test_array, sizeof(test_array))) {
        printf("All bytes are zero\n");
    } else {
        printf("Not all bytes are zero\n");
    }

    return 0;
}
