#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 256

int main() {
    FILE *fp;
    char path[MAX_LEN];

    // run the command and capture the output
    fp = popen("echo %username%", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        return 1;
    }

    // read the output into the path variable
    if (fgets(path, sizeof(path), fp) != NULL) {
        // remove newline character at the end
        path[strcspn(path, "\n")] = 0;

        // your captured output is now in the path variable
        printf("Captured username: %s\n", path);
    }

    // close the pipe
    pclose(fp);

    return 0;
}
