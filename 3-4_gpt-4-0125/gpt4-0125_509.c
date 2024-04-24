char title[100]; // Allocate space for 99 characters plus the terminating null character
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, b;
    char title[100]; // Allocate array on the stack
    FILE *fp;

    fp = fopen("input2.txt", "r");
    if (fp == NULL)
    {
         printf ("Error: file cannot be found\n");
         return 1;
    }

    fscanf(fp, "<%d>\n<%d>", &m, &b);
    printf("%d\n%d\n", m, b); // Added newline for better output formatting

    // Ensure the format string to prevent buffer overflow. "%99s" reads up to 99 
    // characters, leaving room for the terminating null byte.
    fscanf(fp, "<%99s>", title); // No '&' since arrays decay to pointers

    printf("%s\n", title); // Print the title to verify it was read successfully

    fclose(fp);
    return 0;
}

