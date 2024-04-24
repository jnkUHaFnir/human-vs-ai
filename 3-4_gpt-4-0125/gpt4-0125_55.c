#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int r = 2; // Rows
    int c = 3; // Columns
    char line[1024]; // Adjust size as needed for your input
    int arr[r][c];
    int count = 0;

    // Prompt the user for input
    printf("Enter numbers: ");
    // Read the whole line
    if (fgets(line, sizeof(line), stdin) != NULL) {
        char *token = strtok(line, " "); // Start tokenizing the string

        for(int i = 0; i < r && token != NULL; i++) {
            for(int j = 0; j < c && token != NULL; j++) {
                arr[i][j] = atoi(token); // Convert string to int and assign to array
                count++; // Increment count for each successful number extraction
                token = strtok(NULL, " "); // Get next token
            }
        }
        
        // Check if we've got enough input
        if(count < r*c) {
            printf("Insufficient datapoints. Expected %d, got %d.\n", r*c, count);
            // Handle error, e.g., ask for input again or exit.
            return 1;
        }
        
        // Optional: Print array to verify input.
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Error reading input.\n");
        return 1;
    }

    return 0;
}
