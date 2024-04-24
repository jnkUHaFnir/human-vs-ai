#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *imagetmp = argv[1];
    char *imagefile = malloc(strlen(argv[1]) + 1);
    char *unpackdir = malloc(strlen(argv[1]) + 1);

    if (imagefile == NULL || unpackdir == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    strcpy(imagefile, imagetmp);
    strcpy(unpackdir, imagetmp);

    // Remove substring ".img" from imagefile
    char *pch = strstr(imagefile, ".img");
    if (pch != NULL) {
        *pch = '\0';
    }

    // Print strings
    puts(imagefile);
    puts(unpackdir);

    // Free allocated memory
    free(imagefile);
    free(unpackdir);

    return 0;
}
