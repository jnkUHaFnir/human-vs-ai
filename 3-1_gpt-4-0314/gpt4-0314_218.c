#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // ... (assuming parameterArray is initialized)

    unsigned char *src = NULL; // Initialize src to NULL
    size_t total_length = 0;  // Keep track of the total length

    // ... (for loop iterating through parameterArray)

    int length = (parameterArray[i].sizeInBits / 8) + 1; // Check how long array should be
    unsigned char tmp[length]; // Declare array

    memcpy(tmp, (char*)&parameterArray[i].valueU8, length); // In this case copy char to array

    total_length += length; // Update the total length
    src = realloc(src, total_length); // Reallocate space for total string

    if (src == NULL) { // Check for realloc failure
        printf("Memory allocation failed!\n");
        return 1;
    }

    memcpy(src + total_length - length, tmp, length); // Merge

    // ... (closing the loop and continue with the rest of your code)
}
