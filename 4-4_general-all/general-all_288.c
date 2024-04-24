#include <stdio.h>
#include <string.h>

int main() {
    char cmd[128];

    while (fgets(cmd, sizeof(cmd), stdin) != NULL) {
        // Remove the newline character at the end of the input string
        cmd[strcspn(cmd, "\n")] = '\0';

        // Compare input with "exit" to exit the loop
        if (strcmp(cmd, "exit") == 0) {
            break;
        }

        // Handle other commands
        printf("Command received: %s\n", cmd);
    }

    // Code after the loop
    printf("Exited the loop\n");

    return 0;
}
