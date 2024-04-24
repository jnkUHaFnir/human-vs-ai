#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char str[1024]; // Choose an appropriate size for the buffer
    int i;

    str[0] = '\0'; // Null-terminate the string

    // Concatenate all command line arguments into a single string
    for (i = 0; i < argc; i++) {
        strcat(str, argv[i]);
        strcat(str, " "); // Add a space between arguments
    }

    printf("Whole command line: %s\n", str);

    // Your existing code for processing command line options
    int opt;
    while ((opt = getopt(argc, argv, "n:i")) != -1) {
        switch (opt) {
            case 'n':
                printf("n was %s\n", optarg);
                break;
            case 'i':
                printf("i was %s\n", optarg);
                break;
        }
    }

    return 0;
}
