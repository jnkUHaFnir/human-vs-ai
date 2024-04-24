#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, b;
    char *title;
    FILE *fp;

    fp = fopen("input2.txt", "r");
    if (fp == NULL)
    {
         printf("Error: file cannot be found\n");
         return 1;
    }

    fscanf(fp, "<%d>\n<%d>", &m, &b);
    printf("%d\n%d", m, b);

    // Dynamically allocate memory for title
    title = malloc(100 * sizeof(char)); // Assuming a maximum string length of 100 characters
    if (title == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    fscanf(fp, "<%99[^\n]>", title); // Read up to 99 characters into title, stopping at '\n'

    printf("\nTitle: %s\n", title);

    free(title); // Free allocated memory

    fclose(fp);
    return 0;
}
