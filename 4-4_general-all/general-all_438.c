#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define the command to check the location of the program
    const char *command = "which Rscript";

    // Execute the command using system and store the result
    int status = system(command);

    // Check if the command was executed successfully
    if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
        printf("Rscript is installed on the system.\n");
    } else {
        printf("Rscript is not installed on the system.\n");
    }

    return 0;
}
