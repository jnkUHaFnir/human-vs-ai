#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *address = NULL;
    char buffer[1000]; // Buffer to store each line read

    size_t totalSize = 0; // Total size of the address
    char *temp; // Temporary pointer for realloc

    printf("Enter the address of the employee (Press Enter twice to finish):\n");

    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            // Error handling or end of input
            break;
        }

        // Remove newline character from buffer
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
            len--;
        }

        // Dynamically allocate/reallocate memory for address
        temp = realloc(address, totalSize + len + 1);
        if (temp == NULL) {
            // Error handling for memory allocation failure
            printf("Memory allocation failed\n");
            if (address) free(address);
            return 1;
        }
        address = temp;

        // Copy the buffer content to the address
        strncpy(address + totalSize, buffer, len);
        totalSize += len;

        // Check for empty line to finish reading
        if (len == 0) {
            break;
        }
    }

    // Add null-terminator at the end
    address[totalSize] = '\0';

    printf("Address entered: %s\n", address);

    // Free dynamically allocated memory
    free(address);

    return 0;
}
