    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    int main(int argc, const char* argv[])
    {
        int argcCpy = argc;
        char* argvCpy[10] = {};
        if (argc > 9)
        {
            return 1;
        }
        
        for(int i = argc; i > 0; i--)
        {
            if (argv[i] == NULL)
            {
                argvCpy[i] = NULL;
            }
            else
            {
                argvCpy[i] = (char *) malloc(strlen(argv[i]));
                if (argvCpy[i] != NULL)
                {
                    strcpy(argvCpy[i], argv[i]);
                }
            }
        }
        
        for (int i = 0; i <= argcCpy; i++)
        {
            if (argvCpy[i] != NULL)
            {
                printf("Count: %d, string: %s\n", i, argvCpy[i]);
            }
            else
            {
                printf("Count: %d, string is null\n", i);
            }
        }
        return 0;
    }