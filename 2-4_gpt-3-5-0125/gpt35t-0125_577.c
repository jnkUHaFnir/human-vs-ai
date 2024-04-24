#include <stdio.h>
#include <stdlib.h>

int main() {
    char username[100];
    FILE *fp;

    // Execute the command and read the output
    fp = popen("echo %username%", "r");
    if (fp == NULL) {
        printf("Failed to execute command\n");
        return 1;
    }

    // Read the output into the username variable
    fgets(username, sizeof(username), fp);

    // Close the file pointer
    pclose(fp);

    // Remove the newline character at the end
    username[strcspn(username, "\n")] = 0;

    // Insert the username into a string
    char output[100];
    sprintf(output, "Hello, %s!", username);

    printf("%s\n", output);

    return 0;
}
