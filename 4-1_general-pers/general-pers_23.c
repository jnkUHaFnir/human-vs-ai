#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *imagetmp = argv[1];
    char *imagefile = strdup(imagetmp); // Create a copy of the input string
    char *unpackdir = strdup(imagetmp); // Create a copy of the input string

    // Remove substring from char imagefile
    char *pch = strstr(imagefile, ".img");
    if (pch != NULL) {
        *pch = '\0';
    }

    // Print strings
    puts(imagefile);
    puts(unpackdir);

    // Free memory
    free(imagefile);
    free(unpackdir);

    return 0;
}
