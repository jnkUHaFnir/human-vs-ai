#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* my_strdup(const char* src)
{
    size_t len = strlen(src) + 1;
    char* dest = (char*) malloc(len);

    if (dest != NULL)
        strcpy(dest, src);

    return dest;
}
void cleanup() {
    free(dup);
    for (size_t i = 0; i < ntok; ++i)
        free(toks[i]);
    free(toks);
}

// Usage:
if (!newtoks)
    cleanup();
