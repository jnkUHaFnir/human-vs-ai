#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *imagetmp = argv[1];
    char *imagefile = imagetmp;
    char *unpackdir = (char *) malloc(strlen(imagetmp) + 1);

    // Remove substring from char imagefile
    char *pch;
    pch = strstr(imagefile, ".img");
    strncpy(unpackdir, imagefile, pch - imagefile);
    unpackdir[pch - imagefile] = '\0';

    // Print strings
    puts(imagefile);
    puts(unpackdir);

    free(unpackdir);

    return 0;
}
