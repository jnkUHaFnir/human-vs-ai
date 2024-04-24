#include <stdio.h>
#include <string.h>

int main() {
    char cmd[128];

    if(fgets(cmd, 128, stdin) != NULL){
        // Removing the trailing newline character if it exists
        cmd[strcspn(cmd, "\n")] = '\0';

        if(strcmp(cmd, "exit") == 0) {
            // stuff
            printf("Exiting...\n");
        } else {
            // Handle other commands
            printf("Command: %s\n", cmd);
        }
    }

    return 0;
}
