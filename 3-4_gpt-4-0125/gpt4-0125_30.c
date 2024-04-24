#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *line = NULL;   // Pointer to the buffer, initially NULL
    size_t len = 0;      // Size of the buffer, initially 0
    ssize_t nread;       // Number of bytes read
  
    printf("Please enter a line:\n");
  
    // Read the line from stdin
    nread = getline(&line, &len, stdin);
  
    if (nread == -1) {
        printf("Error reading line\n");
    } else {
        // Successfully read the line, print it
        printf("You entered: %s", line);
        // Note: 'line' contains the newline character if the user pressed enter.
    }
  
    // Free the allocated memory
    free(line);

    return 0;
}
