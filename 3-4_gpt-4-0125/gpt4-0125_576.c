#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 128

int main() {
    FILE *fp;
    char path[BUFFER_SIZE];

    // Open the command for reading
    fp = popen("echo %username%", "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
    }

    // Read the output a line at a time - output it.
    if (fgets(path, sizeof(path), fp) != NULL) {
        // Remove trailing newline
        size_t len = strlen(path);
        if (len > 0 && path[len-1] == '\n') {
            path[len-1] = '\0';
        }

        printf("Username: %s\n", path);
    } else {
        printf("Failed to retrieve output\n");
    }

    // Close
    pclose(fp);

    return 0;
}
