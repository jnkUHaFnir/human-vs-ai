#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *result = malloc(1); // allocate memory for initial empty string
    result[0] = '\0'; // ensure the string is null-terminated
    
    // Build string out of variable-length data
    // Simulating a loop similar to Java code
    for (int i = 0; i < 3; i++) {
        char buffer[20];
        sprintf(buffer, "%d", i);
        
        // Append string based on condition
        if (i < 2) {
            strcat(result, buffer); // Append buffer to result
        } else {
            char appendStr[] = "]";
            strcat(result, appendStr); // Append "]" to result
        }
    }
    
    // Print final concatenated string
    printf("%s\n", result);

    // Free memory allocated for result
    free(result);

    return 0;
}
