#include <stdio.h>

int main() {
    char command[50] = "echo %username%";
    char result[50];
    FILE *fp;

    // Open the command for reading
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        return 1;
    }

    // Read the output and store it in the result variable
    if (fgets(result, sizeof(result), fp) != NULL) {
        // Trim the newline character at the end
        result[strcspn(result, "\n")] = 0;
    }

    // Print the result
    printf("Username: %s\n", result);

    // Close the file pointer
    pclose(fp);

    return 0;
}
