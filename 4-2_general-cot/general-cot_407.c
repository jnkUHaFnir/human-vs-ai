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
    printf("%d\n%d\n", m, b);

    // Dynamically allocate memory for the title
    title = (char *)malloc(100 * sizeof(char)); // Assuming maximum length of title is 100 characters

    if (title == NULL)
    {
        printf("Error: memory allocation failed\n");
        return 1;
    }

    fscanf(fp, "<%99[^>]>", title); // Read up to 99 characters until '>' is found
    printf("%s\n", title);

    fclose(fp);
    free(title); // Free the allocated memory

    return 0;
}
