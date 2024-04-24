#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char line[100]; // Assume maximum line length is 100 characters
    int numbers[100]; // Assume maximum number of integers in a line is 100
    int numCount;

    // Read lines until EOF
    while (fgets(line, sizeof(line), stdin) != NULL) {
        numCount = 0;

        // Tokenize the line using strtok
        char *token = strtok(line, ":, \n");
        while (token != NULL) {
            // Convert token to integer and store in array
            numbers[numCount++] = atoi(token);

            // Get the next token
            token = strtok(NULL, ":, \n");
        }

        // Use the integers from the most recently scanned line
        for (int i = 0; i < numCount; i++) {
            printf("%d ", numbers[i]); // Print the integers from the current line
            // You can perform other tasks here with the numbers array
        }
        printf("\n");
    }

    return 0;
}
