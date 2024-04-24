#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char command_line[1024] = "";

    for (int i = 0; i < argc; i++) {
        strcat(command_line, argv[i]);
        strcat(command_line, " ");
    }

    printf("Command line: %s\n", command_line);

    return 0;
}
