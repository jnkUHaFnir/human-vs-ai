#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int i;
    char commandLine[500] = ""; // Define a string to store the command line

    // Concatenate all arguments into the commandLine string
    for (i = 0; i < argc; i++) {
        strcat(commandLine, argv[i]);
        strcat(commandLine, " ");
    }

    printf("The whole command line: %s\n", commandLine);

    return 0;
}
The whole command line: ./a.out -n 67 89 78 -i 9
