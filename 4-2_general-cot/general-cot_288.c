#include <stdio.h>
#include <string.h>

int main() {
    char cmd[128];

    if (fgets(cmd, sizeof(cmd), stdin) != NULL) {
        // Removing the newline character if it exists
        cmd[strcspn(cmd, "\n")] = '\0';

        // Comparing the input string with "exit"
        if (strcmp(cmd, "exit") == 0) {
            printf("Exiting...\n");
            // Add your exit logic here
        } else {
            printf("Input was: %s\n", cmd);
        }
    }

    return 0;
}
