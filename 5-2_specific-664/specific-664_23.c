#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <imagefile>\n", argv[0]);
        return 1;
    }

    char *imagetmp = argv[1];
    char *imagefile = strdup(imagetmp); // Duplicate the original string
    char *unpackdir = strdup(imagetmp); // Duplicate the original string

    // Remove substring from imagefile
    char *pch = strstr(imagefile, ".img");
    if (pch != NULL) {
        *pch = '\0'; // Set the character at the location to null terminator
    }

    // Print strings
    printf("%s\n", imagefile);
    printf("%s\n", unpackdir);

    free(imagefile); // Free dynamically allocated memory
    free(unpackdir); // Free dynamically allocated memory

    return 0;
}
