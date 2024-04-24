#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char str[1000] = ""; // Initialize an empty string to store the command line
    
    for (int i = 0; i < argc; i++) {
        strcat(str, argv[i]); // Concatenate each argument to the string
        if (i < argc - 1) {
            strcat(str, " "); // Add a space between arguments
        }
    }

    printf("Whole command line: %s\n", str);

    return 0;
}
