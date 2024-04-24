#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char cmdline[4096] = ""; // Assuming a maximum length for the command line

    // Concatenate all the command line arguments
    for (int i = 0; i < argc; i++) {
        strcat(cmdline, argv[i]);
        strcat(cmdline, " "); // Add a space between arguments
    }

    printf("Whole command line: %s\n", cmdline);

    return 0;
}
