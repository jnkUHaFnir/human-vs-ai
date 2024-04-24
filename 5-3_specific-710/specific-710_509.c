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
    printf("%d\n%d\n", m, b);

    // Allocate memory for title
    title = (char *)malloc(100 * sizeof(char)); // Allocating 100 characters for now

    if (title == NULL)
    {
        printf("Error: memory allocation failed\n");
        return 1;
    }

    fscanf(fp, "<%99[^\n]>", title); // Read up to 99 characters (avoid buffer overflow)

    // Print the title
    printf("%s\n", title);

    // Free allocated memory
    free(title);
    
    fclose(fp);
    return 0;
}
