#include <stdio.h>
#include <stdlib.h>

#define MAX_USERNAME_LENGTH 256

int main() {
    char username[MAX_USERNAME_LENGTH];
    FILE *fp;

    // Use popen instead of system to safely capture the command output
    fp = popen("echo %username%", "r");
    if (fp == NULL) {
        perror("Error executing command");
        return 1;
    }

    if (fgets(username, sizeof(username), fp) != NULL) {
        // Remove the newline character at the end
        username[strcspn(username, "\n")] = '\0';

        // Print the captured username
        printf("Username: %s\n", username);

        // You can now use the username string in your code securely
    } else {
        printf("Failed to capture username\n");
    }

    pclose(fp);

    return 0;
}
