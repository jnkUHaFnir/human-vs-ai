#include <stdio.h>
#include <string.h>

#define MAX_COMMAND_OUTPUT_SIZE 1024

int main() {
    FILE *fp;
    char command_output[MAX_COMMAND_OUTPUT_SIZE];
    char result_string[MAX_COMMAND_OUTPUT_SIZE];

    // Run the command and capture the output
    fp = popen("echo %username%", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        return 1;
    }

    // Read the output of the command into a string
    if (fgets(command_output, sizeof(command_output), fp) != NULL) {
        // Remove the newline character at the end of the output
        command_output[strcspn(command_output, "\n")] = '\0';

        // Copy the command output to the result string
        snprintf(result_string, sizeof(result_string), "Username: %s", command_output);
        printf("%s\n", result_string);
    }

    pclose(fp);

    return 0;
}
