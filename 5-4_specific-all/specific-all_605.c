#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char line[100]; // Assuming a maximum line length of 100 characters
    int integers[100]; // Assuming a maximum of 100 integers per line
    char *token;
    int i, numIntegers;

    while (fgets(line, sizeof(line), stdin) != NULL) {
        // Reset the array for each line
        memset(integers, 0, sizeof(integers));

        numIntegers = 0;
        token = strtok(line, ":,\n"); // Tokenize the line based on delimiters ":," and newline

        // Parse the integers and store them in the array
        while (token != NULL) {
            integers[numIntegers++] = atoi(token);
            token = strtok(NULL, ":,\n");
        }

        // Use the values from the most recently scanned line to perform other tasks
        for (i = 0; i < numIntegers; i++) {
            // Example: Print the integers for demonstration
            printf("%d\n", integers[i]);
        }
    }

    return 0;
}
