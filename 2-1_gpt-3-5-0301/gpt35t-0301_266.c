#include <stdio.h>
#include <stdlib.h> // required for malloc() and free()

int main()
{
    int i;
    char** t;

    // Allocate an array of 100 char pointers
    t = (char**)malloc(100 * sizeof(char*));

    // Allocate an array of 16 chars for each of the 100 pointers
    for(i=0; i<100; i++)
    {
        t[i] = (char*)malloc(16 * sizeof(char));
    }

    // You can now use the string table

    // Free the memory allocated for each string
    for(i=0; i<100; i++)
    {
        free(t[i]);
    }

    // Free the memory allocated for the array of pointers
    free(t);

    return 0;
}
