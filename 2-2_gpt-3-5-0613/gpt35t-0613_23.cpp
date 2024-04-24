#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *imagetmp = argv[1];
    char *imagefile = imagetmp;
    char *unpackdir = imagetmp;

    // Remove substring from char imagefile
    char *pch;
    pch = strstr(imagefile, ".img");
    
    if (pch != NULL) {
        *pch = '\0';
    }

    // Print the strings
    puts(imagefile);
    puts(unpackdir);

    return 0;
}
