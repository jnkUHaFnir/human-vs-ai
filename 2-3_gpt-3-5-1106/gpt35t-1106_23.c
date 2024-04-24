int main(int argc, char *argv[])
{
    char *imagetmp = argv[1];
    char *imagefile = strdup(imagetmp); // Make a copy of imagetmp
    char *unpackdir = strdup(imagetmp); // Make a copy of imagetmp

    // Remove substring from char imagefile
    char *pch;
    pch = strstr(imagefile, ".img");
    memmove(pch, pch + 4, strlen(pch + 4) + 1); // Shift remaining characters to overwrite ".img"

    // Print strings
    puts(imagefile);
    puts(unpackdir);

    free(imagefile); // Free up the memory allocated by strdup
    free(unpackdir); // Free up the memory allocated by strdup
    return 0;
}
