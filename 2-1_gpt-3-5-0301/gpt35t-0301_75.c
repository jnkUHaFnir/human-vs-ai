int main(int argc, const char* argv[])
{   
    char* argvCpy[10] = {};

    for(int i = argc - 1; i >= 0; i--)
    {   
        argvCpy[i] = (char*) malloc(strlen(argv[i]) + 1);
        strncpy(argvCpy[i], argv[i], strlen(argv[i]) + 1);
        printf("\nCount: %d, string: %s", i, argvCpy[i]);
    }

    // Free the allocated memory
    for(int i = 0; i < argc; i++)
    {
        free(argvCpy[i]);
    }

    return 0;
}
