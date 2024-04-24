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
         printf ("Error: file cannot be found\n");
         return 1;
    }

    fscanf(fp, "<%d>\n<%d>", &m, &b);
    printf("%d\n%d", m, b);

    title = (char*)malloc(100); // Allocate memory for the title
    if (title == NULL)
    {
        printf("Error: Failed to allocate memory for title\n");
        return 1;
    }

    if (fscanf(fp, "<%99[^>]>", title) != 1) // Read up to 99 characters until '>'
    {
        printf("Error reading title from file\n");
        return 1;
    }

    printf("\n%s", title);

    free(title); // Free allocated memory
    fclose(fp);
    return 0;
}
