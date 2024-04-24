#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char** t;
    
    t = (char**)malloc(100 * sizeof(char*)); // Allocate memory for 100 strings

    for (i = 0; i < 100; i++)
    {
        t[i] = (char*)malloc(16 * sizeof(char) + 1); // Allocate memory for each string
        if (t[i] == NULL) {
            // Handle memory allocation failure
            printf("Memory allocation failed for t[%d]\n", i);
            return 1;
        }
        // Do not forget to null-terminate the string
        t[i][16] = '\0';
    }

    // Use the dynamically allocated memory

    // Free the memory
    for (i = 0; i < 100; i++)
    {
        free(t[i]);
    }

    free(t);
    
    return 0;
}
