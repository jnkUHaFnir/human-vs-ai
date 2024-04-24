#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int i;
    char cmdline[1024] = ""; // Allocate a buffer to store the command line

    // Concatenate all command line arguments into a single string
    for (i = 0; i < argc; i++) {
        strcat(cmdline, argv[i]);
        strcat(cmdline, " "); // Separate arguments by space
    }

    printf("Whole command line: %s\n", cmdline);

    return 0;
}
