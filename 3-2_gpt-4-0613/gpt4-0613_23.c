#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) 
{
    // Check if filename is provided
    if(argc < 2) {
        printf("Provide filename as argument!\n");
        return -1;
    }
    
    char *imagefile = argv[1];

    // Make a copy to store the modified string
    char *unpackdir = malloc(strlen(imagefile) + 1);
    strcpy(unpackdir, imagefile);

    // Remove substring from unpackdir
    char * pch;
    pch = strstr (unpackdir, ".img");
    if(pch) {
        *pch = '\0';
    }

    // Print strings
    puts(imagefile);
    puts(unpackdir);

    // Remember to free memory
    free(unpackdir); 
    return 0;
}
