int main(int argc, char *argv[])
{
    char imagefile[100];
    strncpy(imagefile, argv[1], sizeof(imagefile) - 1);
    //char *unpackdir = argv[1]; you can use argv[1] directly
    // Remove substring from char imagefile
    char * pch;
    pch = strstr (argv[1],".img");
    strncpy (pch,"",6);
    // Print strings
    puts (imagefile);
    puts (argv[1]);
    return 0;
}