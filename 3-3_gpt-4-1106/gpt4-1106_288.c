#include <stdio.h>
#include <string.h>

int main() {
    char cmd[128];
    
    printf("Enter a command (type 'exit' to stop): ");

    while (fgets(cmd, sizeof(cmd), stdin)) {
        // Remove the newline character if present
        cmd[strcspn(cmd, "\n")] = 0;

        // Check if the input is "exit"
        if (strcmp(cmd, "exit") == 0) {
            break; // Exit the loop
        }
        
        // Process other commands here
        printf("You entered: %s\n", cmd);
        printf("Enter a command (type 'exit' to stop): ");
    }

    printf("Exiting the program.\n");
    return 0;
}
