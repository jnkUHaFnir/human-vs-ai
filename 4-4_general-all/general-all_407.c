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

    // Allocate memory for the title
    title = (char *)malloc(100 * sizeof(char)); // Assume max length of title is 100 characters
    if (title == NULL)
    {
        printf("Error: Memory allocation failed\n");
        fclose(fp);
        return 1;
    }

    fscanf(fp, "<%99[^>]>", title); // Read at most 99 characters or until '>'
    printf("%s\n", title);

    free(title); // Free the allocated memory

    fclose(fp);
    return 0;
}
