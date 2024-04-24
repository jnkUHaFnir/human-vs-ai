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

    // Allocate memory for title
    title = (char*)malloc(100 * sizeof(char)); // Assuming a maximum length of 100 characters
    if (title == NULL)
    {
        printf("Error allocating memory\n");
        return 1;
    }

    fscanf(fp, "<%99s>", title); // Read a string up to 99 characters (leave 1 for null terminator)
    printf("\n%s", title);

    free(title); // Free dynamically allocated memory

    fclose(fp);
    return 0;
}
