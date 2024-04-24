#include <stdio.h>
#include <stdlib.h>

#define MAX_OUTPUT_SIZE 256

char* getCommandOutput(const char* command) {
    FILE* fp;
    char output[MAX_OUTPUT_SIZE];
    char* result = NULL;

    fp = popen(command, "r");
    if (fp == NULL) {
        perror("Error opening pipe");
        return NULL;
    }

    if (fgets(output, sizeof(output), fp) != NULL) {
        // Remove newline character if present
        char* newline = strchr(output, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }
        
        // Allocate memory for result and copy the output
        result = (char*)malloc(strlen(output) + 1);
        if (result != NULL) {
            strcpy(result, output);
        } else {
            perror("Memory allocation failed");
        }
    }

    pclose(fp);
    return result;
}

int main() {
    char* username = getCommandOutput("echo %username%");
    
    if (username != NULL) {
        printf("Username: %s\n", username);
        free(username); // Free the allocated memory
    } else {
        printf("Failed to get username\n");
    }
    
    return 0;
}
