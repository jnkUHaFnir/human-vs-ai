#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char username[100];

    // Run the command and open a pipe to read its output
    fp = popen("echo %username%", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        return 1;
    }

    // Read the output and store it in "username"
    fgets(username, sizeof(username), fp);

    // Remove the newline character at the end (if present)
    username[strcspn(username, "\n")] = 0;

    printf("Username: %s\n", username);

    // Close the pipe
    pclose(fp);

    return 0;
}
