#include <stdio.h>

int main() {
    FILE *fp;
    char username[50]; // Adjust the size of the array based on the expected output size

    // Open pipe to execute the command
    fp = popen("echo %username%", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        return 1;
    }

    // Read the output into the username array
    if (fgets(username, sizeof(username), fp) != NULL) {
        // Remove the newline character from the output
        username[strcspn(username, "\n")] = 0;
        printf("Username: %s\n", username);
    }

    pclose(fp);
    return 0;
}
