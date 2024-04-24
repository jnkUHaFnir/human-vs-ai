#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <imagefile>\n", argv[0]);
        return 1;
    }

    char *imagetmp = argv[1];
    char *imagefile = strdup(imagetmp); // Allocate memory for imagefile
    char *unpackdir = malloc(strlen(imagetmp) + 1); // Allocate memory for unpackdir

    // Check if memory allocation was successful
    if (imagefile == NULL || unpackdir == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Remove ".img" extension from imagefile
    strncpy(unpackdir, imagetmp, strlen(imagetmp) - 4);
    unpackdir[strlen(imagetmp) - 4] = '\0'; // Null-terminate the string

    // Print strings
    printf("%s\n", imagefile);
    printf("%s\n", unpackdir);

    // Free allocated memory
    free(imagefile);
    free(unpackdir);

    return 0;
}
