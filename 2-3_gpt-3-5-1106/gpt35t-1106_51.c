#include <stdio.h>
#include <stdlib.h>

int main() {
    char *address = NULL; // The char* variable to store the address
    size_t size = 0; // Initial size of the buffer
    ssize_t chars_read; // Number of characters read

    printf("Enter the employee's address (press Enter twice to finish):\n");

    // Loop to read multiple lines of input
    do {
        // Use getline to read a line of input
        chars_read = getline(&address, &size, stdin);

        // If getline was successful and the input was not just a newline, process the input
        if (chars_read > 0 && address[0] != '\n') {
            // Print the address (or do something else with it)
            printf("Address: %s", address);
        }
    } while (chars_read > 0 && address[0] != '\n'); // Loop until an empty line is entered

    // Free the dynamically allocated buffer
    free(address);

    return 0;
}
