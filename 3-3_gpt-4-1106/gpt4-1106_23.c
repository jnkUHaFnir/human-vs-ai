#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename.img\n", argv[0]);
        return 1;
    }
    
    // Make a copy of the input argument, since we shouldn't modify argv directly.
    char *imagefile = strdup(argv[1]);
    if (imagefile == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }
    
    // Make another copy for the unpackdir.
    char *unpackdir = strdup(imagefile);
    if (unpackdir == NULL) {
        perror("Failed to allocate memory");
        free(imagefile);
        return 1;
    }

    // Remove ".img" substring from imagefile.
    char *pch;
    pch = strstr(imagefile, ".img");
    if (pch != NULL) {
        *pch = '\0'; // This effectively removes the ".img" by adding a null terminator.
    }

    // Print strings
    puts(imagefile);  // Expects to print 'mysuperimage'
    puts(unpackdir);  // Expects to print 'mysuperimage.img'

    // Free the allocated memory before returning.
    free(imagefile);
    free(unpackdir);

    return 0;
}
mysuperimage
mysuperimage.img
