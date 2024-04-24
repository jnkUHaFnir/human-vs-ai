#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char** t;
    t = (char**)malloc(16 * sizeof(char*));

    for (i = 0; i < 16; i++)
    {
        t[i] = (char*)malloc(16 * sizeof(char));
    }

    // Do something with the 2D array

    // Don't forget to free the memory allocated
    for (i = 0; i < 16; i++)
    {
        free(t[i]);
    }

    free(t);

    return 0;
}
