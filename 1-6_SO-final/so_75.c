    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    int main(int argc, const char* argv[])
    {   
        int argcCpy = argc;
        char* argvCpy[10];
        if (argc > 9)
        {
            return 1;
        }
        for(argcCpy = argc; argcCpy>=0; argcCpy--)
        {
            if (argv[argcCpy] == NULL)
            {
                argvCpy[argcCpy] = NULL;
            }
            else
            {
                argvCpy[argcCpy] = malloc(strlen(argv[argcCpy]) + 1);
                strcpy(argvCpy[argcCpy], argv[argcCpy]);
                printf("\nCount: %d, string: %s", argcCpy, argvCpy[argcCpy]);
            }
        }
        return 0;
    }