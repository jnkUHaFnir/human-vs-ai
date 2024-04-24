#include <stdio.h>
#include <string.h>

int main() {
    char cmd[128];
    
    if (fgets(cmd, 128, stdin) != NULL) {
        cmd[strcspn(cmd, "\n")] = '\0'; // Removing the trailing newline character
        
        if (strcmp(cmd, "exit") == 0) {
            // "exit" was entered
            printf("Exiting program...\n");
        } else {
            // Other commands were entered
            printf("Command entered: %s\n", cmd);
        }
    }
    
    return 0;
}
