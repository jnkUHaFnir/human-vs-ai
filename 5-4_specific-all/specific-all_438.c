#include <stdio.h>

int main() {
    FILE *fp;
    char path[1035];

    // Open the command for reading
    fp = popen("which Rscript", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        return 1;
    }

    // Read the output a line at a time - it should only return one line
    while (fgets(path, sizeof(path)-1, fp) != NULL) {
        printf("Program installation path: %s", path);
    }

    // Close the output file stream
    pclose(fp);

    return 0;
}
