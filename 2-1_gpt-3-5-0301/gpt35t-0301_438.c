#include <stdio.h>
#include <stdlib.h>

// Function to check if a program is installed
int isProgramInstalled(char *program) {
    char cmd[100];

    // Create the command to check if the program is installed
    snprintf(cmd, sizeof(cmd), "which %s >/dev/null 2>&1", program);

    // Execute the command and check the return code
    int result = system(cmd);
    if (result == 0) {
        // Program is installed
        return 1;
    } else {
        // Program is not installed
        return 0;
    }
}

int main() {
    // Check if Rscript is installed
    if (isProgramInstalled("Rscript")) {
        printf("Rscript is installed\n");
    } else {
        printf("Rscript is not installed\n");
    }

    return 0;
}
