#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMMAND_MAX_LENGTH 100

int main() {
    char command[COMMAND_MAX_LENGTH];
    FILE *fp;
    char path[100];

    // Define the command to execute
    snprintf(command, COMMAND_MAX_LENGTH, "which Rscript");

    // Open the command for reading
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    // Read the output of the command
    while (fgets(path, sizeof(path), fp) != NULL) {
        printf("Rscript location: %s", path);
    }

    // close
    pclose(fp);

    return 0;
}
