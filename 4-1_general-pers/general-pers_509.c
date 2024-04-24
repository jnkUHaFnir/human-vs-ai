#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, b;
    char *title = NULL;
    FILE *fp;

    fp = fopen("input2.txt", "r");
    if (fp == NULL)
    {
        printf("Error: file cannot be found\n");
        return 1;
    }

    fscanf(fp, "<%d>\n<%d>", &m, &b);
    printf("%d\n%d\n", m, b);

    // Dynamically allocate memory for the title buffer
    title = (char*)malloc(100 * sizeof(char)); // assuming a maximum title length of 100 characters
    if (title == NULL)
    {
        printf("Error: memory allocation failed\n");
        fclose(fp);
        return 1;
    }

    // Read the title from the file into the allocated buffer
    if (fscanf(fp, "<%99[^>]", title) == 1) // limit the number of characters read to 99, excluding '>' character
    {
        printf("%s\n", title);
    }
    else
    {
        printf("Error: failed to read title\n");
    }

    // Free the allocated memory and close the file
    free(title);
    fclose(fp);
    
    return 0;
}
