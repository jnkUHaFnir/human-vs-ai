#include <stdio.h>
#include <stdlib.h>

int main() {
    char *line = NULL;  // Initialize the line pointer to NULL
    size_t len = 0;     // Initialize the line buffer length to 0
    ssize_t read;       // Declare a variable for the number of characters read

    printf("Enter a line: ");
    read = getline(&line, &len, stdin);  // Read the line from standard input

    if (read == -1) {  // Check if there was an error reading the line
        perror("getline error");
        exit(EXIT_FAILURE);
    }

    printf("You entered: %s", line);

    free(line);  // Free the memory allocated by getline()
    return 0;
}
