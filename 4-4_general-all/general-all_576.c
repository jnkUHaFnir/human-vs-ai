#include <stdio.h>
#include <stdlib.h>

#define MAX_COMMAND_OUTPUT_LENGTH 100

int main() {
    char username[MAX_COMMAND_OUTPUT_LENGTH];
    FILE *fp;

    // Open a pipe to execute the command
    fp = popen("echo %username%", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        return 1;
    }

    // Read the output of the command into the username variable
    if (fgets(username, sizeof(username), fp) == NULL) {
        fprintf(stderr, "Failed to read command output\n");
        pclose(fp);
        return 1;
    }

    // Remove the newline character at the end of the username
    size_t len = strlen(username);
    if (len > 0 && username[len - 1] == '\n') {
        username[len - 1] = '\0';
    }

    // Close the pipe
    pclose(fp);

    // Now you can use the username variable
    printf("Username: %s\n", username);

    return 0;
}
