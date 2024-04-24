#include <stdio.h>
#include <string.h>

#define MAX_OUTPUT_SIZE 100

char* executeCommand(const char* command) {
    char buffer[MAX_OUTPUT_SIZE];
    char* result = NULL;
    
    FILE* fp = popen(command, "r");
    if (fp == NULL) {
        return NULL;
    }
    
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Remove newline character at the end if present
        char* newlinePos = strchr(buffer, '\n');
        if (newlinePos != NULL) {
            *newlinePos = '\0';
        }

        result = strdup(buffer);
    }

    pclose(fp);
    return result;
}

int main() {
    char* username = executeCommand("echo %username%");
    if (username != NULL) {
        printf("Username: %s\n", username);
        free(username); // Remember to free the memory allocated by strdup
    } else {
        printf("Failed to retrieve the username.\n");
    }

    return 0;
}
