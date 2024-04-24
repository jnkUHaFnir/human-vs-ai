#include <stdio.h>
#include <string.h>

int main() {
    char cmd[128];

    if (fgets(cmd, sizeof(cmd), stdin) != NULL) {
        cmd[strcspn(cmd, "\n")] = '\0'; // Remove the newline character at the end

        if (strcmp(cmd, "exit") == 0) {
            // Do something if the input is "exit"
            printf("Exiting the program\n");
        } else {
            // Do something else
            printf("Input was not 'exit'\n");
        }
    }
    
    return 0;
}
