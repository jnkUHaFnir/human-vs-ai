#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* pipe;
    char buffer[128];

    // The command to check if a program exists using "which"
    char* command = "which Rscript";

    pipe = popen(command, "r"); // Open the pipe in read mode
    if (!pipe) {
        perror("popen failed");
        return EXIT_FAILURE;
    }

    // Try to read a line from the pipe
    if (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        printf("Rscript found at: %s", buffer);
    } else {
        printf("Rscript is not installed or not found in PATH.\n");
    }

    // Close the pipe
    pclose(pipe);

    return EXIT_SUCCESS;
}
