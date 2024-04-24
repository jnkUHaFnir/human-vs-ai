#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *imagetmp = argv[1];
    
    // Allocate memory for the imagefile and unpackdir strings
    char *imagefile = malloc(strlen(imagetmp) + 1);
    char *unpackdir = malloc(strlen(imagetmp) + 1);
    
    // Copy imagetmp content to imagefile and unpackdir
    strcpy(imagefile, imagetmp);
    strcpy(unpackdir, imagetmp);

    // Remove substring from imagefile
    char * pch;
    pch = strstr (imagefile,".img");
    if (pch != NULL) {
        *pch = '\0'; // Add null terminator at the position of ".img"
    }

    // Print strings
    puts (imagefile);
    puts (unpackdir);

    // Free allocated memory
    free(imagefile);
    free(unpackdir);

    return 0;
}
