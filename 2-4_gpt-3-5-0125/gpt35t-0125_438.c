#include <stdio.h>

int main() {
    FILE *fp;
    char path[1035];

    // Run the 'which Rscript' command and capture its output
    fp = popen("which Rscript", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        return 1;
    }

    // Read the output of the command
    while (fgets(path, sizeof(path)-1, fp) != NULL) {
        printf("Rscript is installed at: %s", path);
    }

    // Close the command output
    pclose(fp);

    return 0;
}
