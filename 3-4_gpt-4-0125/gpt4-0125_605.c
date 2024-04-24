#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUMS 100 // Assuming each line won't have more than 100 numbers

int main() {
    char line[MAX_LINE_LENGTH];
    int nums[MAX_NUMS]; // Array to store the integers from each line
    char *token;
    
    // Read lines until EOF
    while (fgets(line, sizeof(line), stdin)) {
        // Remove newline character if present
        line[strcspn(line, "\n")] = 0;

        // Tokenize the line based on ':' and ',' delimiters
        token = strtok(line, ":,");
        int i = 0;
        while (token != NULL && i < MAX_NUMS) {
            // Convert token to int and store in the array
            nums[i++] = atoi(token);
            
            // Get next token
            token = strtok(NULL, ":,");
        }

        // Now nums[] contains all the integers from the line, and i is the count
        // You can use this data as needed here:
        for (int j = 0; j < i; ++j) {
            printf("%d ", nums[j]); // Example usage
        }
        printf("\n"); // Move to the next line after processing one line's integers
    }

    return 0;
}
