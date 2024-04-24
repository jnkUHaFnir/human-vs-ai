#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_OUTPUT_SIZE 100

int main() {
    char command_output[MAX_COMMAND_OUTPUT_SIZE];
    FILE *fp;

    fp = popen("echo %username%", "r");
    if (fp == NULL) {
        perror("Error executing command");
        return 1;
    }

    if (fgets(command_output, sizeof(command_output), fp) != NULL) {
        // Remove the newline character at the end
        command_output[strcspn(command_output, "\n")] = 0;

        printf("Output of command: %s\n", command_output);
    } else {
        printf("No output from command\n");
    }

    pclose(fp);

    return 0;
}
