#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <imagename>\n", argv[0]);
        return 1;
    }

    char *imagetmp = argv[1];
    char *imagefile = strdup(imagetmp); // Duplicate the string to avoid modifying the original
    char *unpackdir = strdup(imagetmp); // Duplicate the string to avoid modifying the original

    // Remove ".img" substring from imagefile
    char *pch = strstr(imagefile, ".img");
    if(pch != NULL) {
        *pch = '\0'; // Replace the "." of ".img" with null terminator
    }

    // Print strings
    puts(imagetmp);
    puts(imagefile);
    puts(unpackdir);

    free(imagefile); // Free the duplicated strings
    free(unpackdir);

    return 0;
}
