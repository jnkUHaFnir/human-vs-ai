#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *imagetmp = argv[1];
    char *imagefile = strdup(imagetmp);
    char *unpackdir = strdup(imagetmp);

    // Remove substring from char imagefile
    char *pch;
    pch = strstr(imagefile, ".img");
    if (pch != NULL) {
        *pch = '\0';
    }

    // Print strings
    puts(imagefile);
    puts(unpackdir);

    // Free memory allocated for strings
    free(imagefile);
    free(unpackdir);

    return 0;
}
