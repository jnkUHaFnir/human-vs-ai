#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

int main() {
    FILE *cmd_output;
    char buffer[MAX_BUFFER_SIZE];

    cmd_output = popen("echo %username%", "r");
    if (cmd_output == NULL) {
        perror("popen");
        return 1;
    }

    if (fgets(buffer, MAX_BUFFER_SIZE, cmd_output) != NULL) {
        // Removing newline character from the end
        buffer[strcspn(buffer, "\n")] = 0;
        printf("Username: %s\n", buffer);
    }

    pclose(cmd_output);

    return 0;
}
