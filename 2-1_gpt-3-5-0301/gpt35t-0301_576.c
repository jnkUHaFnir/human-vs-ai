#include <stdio.h>
#include <string.h>

int main() {
    FILE* cmd = popen("echo %username%", "r");
    if (!cmd) {
        fprintf(stderr, "Failed to execute command\n");
        return 1;
    }
    char buffer[128];
    if (!fgets(buffer, sizeof(buffer), cmd)) {
        fprintf(stderr, "Failed to read command output\n");
        return 1;
    }
    pclose(cmd);
    strtok(buffer, "\r\n"); // Remove newline
    char message[128];
    sprintf(message, "Logged in as %s", buffer);
    printf("%s\n", message);
    return 0;
}
Logged in as [your username]
