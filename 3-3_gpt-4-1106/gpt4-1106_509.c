#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, b;
    char title[256];  // Allocate a fixed-size buffer on the stack
    FILE *fp;

    fp = fopen("input2.txt", "r");
    if (fp == NULL)
    {
         printf("Error: file cannot be found\n");
         return 1;
    }

    if (fscanf(fp, "<%d>\n<%d>", &m, &b) == 2) { // Check if both integers are read
        printf("%d\n%d\n", m, b);
    } else {
        printf("Failed to read integers from file\n");
        fclose(fp);
        return 1;
    }

    // It's a good practice to limit the input length to prevent buffer overruns.
    // %255s ensures that we read at most 255 characters into the 256-byte buffer 'title'.
    if (fscanf(fp, " %255[^>]", title) == 1) { // Read until '>' character (not including)
        printf("Title: %s\n", title);
    } else {
        printf("Failed to read title from file\n");
    }

    fclose(fp);
    return 0;
}
