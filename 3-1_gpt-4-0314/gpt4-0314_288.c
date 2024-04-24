#include <stdio.h>
#include <string.h>

int main() {
    char cmd[128];

    while (fgets(cmd, 128, stdin)) {
        if (strcmp(cmd, "exit\n") == 0) {
            // stuff
            break;
        }
    }

    return 0;
}
