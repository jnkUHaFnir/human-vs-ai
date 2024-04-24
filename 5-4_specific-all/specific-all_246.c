#include <stdio.h>
#include <string.h>

int main() {
    int size = 1000; // size of memory block

    // Method 1: Using int
    int* block_int = malloc(size * sizeof(int));
    memset(block_int, 0, size * sizeof(int));
    free(block_int);

    // Method 2: Using char
    char* block_char = malloc(size * sizeof(char));
    memset(block_char, 0, size * sizeof(char));
    free(block_char);

    return 0;
}
