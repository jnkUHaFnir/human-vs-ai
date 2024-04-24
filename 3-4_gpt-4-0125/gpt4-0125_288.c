#include <stdio.h>
#include <string.h> // For strcmp

int main() {
    char cmd[128];

    printf("Enter command: ");
    if (fgets(cmd, 128, stdin) != NULL) {
        // Remove the newline character
        cmd[strcspn(cmd, "\n")] = 0;

        // Now compare the string
        if (strcmp(cmd, "exit") == 0) {
            printf("Exiting...\n");
        } else {
            printf("You entered: %s\n", cmd);
        }
    }
    
    return 0;
}
