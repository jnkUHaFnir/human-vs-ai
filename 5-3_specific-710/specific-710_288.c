#include <stdio.h>
#include <string.h>

int main() {
    char cmd[128];

    if(fgets(cmd, 128, stdin) != NULL) {
        cmd[strcspn(cmd, "\n")] = 0; // Remove the newline character if present
        if(strcmp(cmd, "exit") == 0) {
            // Do something if the input is "exit"
            printf("Exiting...\n");
        } else {
            // Do something else
            printf("Input was not 'exit'\n");
        }
    }

    return 0;
}
