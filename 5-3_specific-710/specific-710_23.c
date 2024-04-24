#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    char *imagetmp = argv[1];
    char *imagefile = strdup(imagetmp);
    char *unpackdir = strdup(imagetmp);

    // Remove substring from char imagefile
    char *pch = strstr(imagefile, ".img");
    if (pch != NULL)
    {
        *pch = '\0';
    }

    // Print strings
    printf("%s\n", imagefile);
    printf("%s\n", unpackdir);

    free(imagefile);
    free(unpackdir);
    return 0;
}
