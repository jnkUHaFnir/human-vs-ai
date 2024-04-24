#include <stdio.h>
#include <stdlib.h> // Include this for malloc

int main()
{
    int i;
    char** t;

    // Allocate memory for array of pointers (16 pointers)
    t = (char**)malloc(16 * sizeof(char*));
    if (t == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < 16; i++) // Corrected the loop condition
    {
        // Allocate memory for each string (16 characters including null terminator)
        t[i] = (char*)malloc(16 * sizeof(char)); 
        if (t[i] == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");

            // To prevent memory leaks, free previously allocated memory
            for (int j = 0; j < i; j++)
            {
                free(t[j]);
            }
            free(t);
            return 1;
        }
    }

    // Access and use the allocated memory

    // Free the allocated memory
    for (i = 0; i < 16; i++)
    {
        free(t[i]);
    }
    free(t);

    return 0;
}
