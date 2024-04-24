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

    // Add code here to use the dynamically allocated table

    // Don't forget to free the allocated memory before exiting the program
    for (i = 0; i < 16; i++)
    {
        free(t[i]);
    }
    free(t);

    return 0;
}
