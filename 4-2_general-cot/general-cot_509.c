#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, b;
    char *title = NULL; // Initialize pointer to NULL
    FILE *fp;

    fp = fopen("input2.txt", "r");
    if (fp == NULL)
    {
         printf("Error: file cannot be found\n");
         return 1;
    }

    fscanf(fp, "<%d>\n<%d>", &m, &b);
    printf("%d\n%d", m, b);

    // Allocate memory for title
    title = calloc(100, sizeof(char)); // Assuming max length of title is 100 characters
    if (title == NULL)
    {
        printf("Error allocating memory\n");
        return 1;
    }

    fscanf(fp, "<%99[^>]>", title); // Read up to 99 characters until '>'
    printf("\n%s", title);

    free(title); // Free allocated memory
    fclose(fp);
    return 0;
}
