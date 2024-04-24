#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char cmdline[1024] = ""; // Assuming maximum length of command line is 1024 characters

    for(int i = 1; i < argc; i++) {
        strcat(cmdline, argv[i]);
        strcat(cmdline, " ");
    }

    printf("Whole command line: %s\n", cmdline);

    return 0;
}
