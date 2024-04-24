#include <stdio.h>
#include <string.h>

int main() {
    char cmd[128];

    if(fgets(cmd, 128, stdin) != NULL && strcmp(cmd, "exit\n") == 0) {
        // stuff
        printf("Exiting...\n");
    }

    return 0;
}
