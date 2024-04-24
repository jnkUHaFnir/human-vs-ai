int main(int argc, char *argv[])
{
    char imagefile[100];
    if(argc < 2) {
       puts("Too few arguments");
       return 1;
    }
    
    strncpy(imagefile, argv[1], sizeof(imagefile) - 1);
    //char *unpackdir = argv[1]; you can use argv[1] directly
    // Remove substring from char imagefile
    char * pch;
    if((pch = strstr (argv[1],".img")))
        *pch = 0; //or '\0';
    else
        puts("Extension not found");
    
    // Print strings
    puts (imagefile);
    puts (argv[1]);
    return 0;
}