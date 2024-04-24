#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <imagename>\n", argv[0]);
        return 1;
    }

    char *imagetmp = argv[1];
    char *imagefile = strdup(imagetmp); // Make a copy to work with
    char *unpackdir = imagefile;

    // Remove substring from char imagefile
    char *pch;
    if ((pch = strstr(imagefile, ".img")) != NULL) {
        *pch = '\0'; // Null terminate at this position
    }

    // Print strings
    puts(imagefile);
    puts(unpackdir);

    free(imagefile); // Free the memory allocated by strdup
    return 0;
}
