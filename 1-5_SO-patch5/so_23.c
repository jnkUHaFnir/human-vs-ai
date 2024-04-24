int main(int argc, char *argv[])
{
    char *imagefile[100];
    strcpy(imagefile, argv[1]);
    char *unpackdir = argv[1];
    // Remove substring from char imagefile
    char * pch;
    pch = strstr (argv[1],".img");
    strncpy (pch,"",6);
    // Print strings
    puts (imagefile);
    puts (unpackdir);
    return 0;
}