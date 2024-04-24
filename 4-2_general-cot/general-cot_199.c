#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char fullCommandLine[4096] = ""; // Assuming maximum length of command line is 4096

    // Concatenate all command line arguments into a single string
    for (int i = 0; i < argc; i++) {
        strcat(fullCommandLine, argv[i]);
        strcat(fullCommandLine, " ");
    }

    printf("Full command line: %s\n", fullCommandLine);

    return 0;
}
