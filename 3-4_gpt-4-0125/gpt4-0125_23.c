#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image name>\n", argv[0]);
        return 1;
    }

    // Allocate memory and copy the image name to imagefile
    char *imagefile = strdup(argv[1]);
    if (!imagefile) {
        perror("Failed to allocate memory");
        return 1;
    }
    char *unpackdir = strdup(imagefile); // Duplicate imagefile
    if (!unpackdir) {
        perror("Failed to allocate memory");
        free(imagefile); // free allocated memory before exit
        return 1;
    }

    // Remove ".img" substring from unpackdir
    char *pch;
    pch = strstr(unpackdir, ".img");
    if (pch) {
        *pch = '\0'; // Terminate the string at the beginning of ".img"
    }

    // Print strings
    puts(imagefile);
    puts(unpackdir);

    // Free the allocated memory
    free(imagefile);
    free(unpackdir);

    return 0;
}
