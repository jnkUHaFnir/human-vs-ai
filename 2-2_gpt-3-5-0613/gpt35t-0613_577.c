#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

int main() {
    FILE* commandOutput = popen("echo %username%", "r");
    if (commandOutput == NULL) {
        printf("Failed to execute command\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, commandOutput);

    // Remove trailing newline character, if present
    if (buffer[strlen(buffer) - 1] == '\n') {
        buffer[strlen(buffer) - 1] = '\0';
    }

    // Copy the command output into a string
    char result[BUFFER_SIZE];
    strcpy(result, buffer);

    pclose(commandOutput);

    printf("Command result: %s\n", result);

    return 0;
}
