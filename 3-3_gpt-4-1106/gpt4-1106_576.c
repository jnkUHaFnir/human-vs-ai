#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER 256 // Define the maximum size of the buffer

int main() {
    FILE *fp;
    char buffer[MAX_BUFFER];
    char result[MAX_BUFFER] = {0}; // Initialize the result array to store the final string

    // Open the command for reading
    fp = popen("echo %username%", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(1);
    }

    // Read the output a line at a time and copy it into the result string
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Assuming the echo output is a single line, we just copy it
        strncpy(result, buffer, sizeof(result));
        // Remove unwanted newline char if present at the end of the string
        size_t len = strlen(result);
        if (len > 0 && result[len - 1] == '\n') {
            result[len - 1] = '\0';
        }
    }

    // Close the command stream
    pclose(fp);

    // Result now contains the username
    printf("The current user is: %s\n", result);

    return 0;
}
