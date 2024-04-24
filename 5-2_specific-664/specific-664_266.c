#include <stdio.h>
#include <stdlib.h> // for malloc, free

int main()
{
    int i;
    char** t;
    t = (char**)malloc(100 * sizeof(char*)); // Allocating memory for an array of 100 char pointers

    for(i = 0; i < 100; i++)
    {
        t[i] = (char*)malloc(16 * sizeof(char)); // Allocating memory for each string in the table
    }

    // Your code here

    // Free the allocated memory
    for(i = 0; i < 100; i++)
    {
        free(t[i]);
    }
    free(t);

    return 0;
}
