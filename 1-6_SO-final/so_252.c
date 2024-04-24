    #include <stdlib.h>
    #include <string.h>
    char *join(const char* s1, const char* s2)
    {
        char* result = malloc(strlen(s1) + strlen(s2) + 1);
        strcpy(result, s1);
        strcat(result, s2);
        return result;
    }