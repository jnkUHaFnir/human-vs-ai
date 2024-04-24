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

    title = (char *)malloc(100 * sizeof(char)); // assuming a maximum string length of 100 characters
    if (title == NULL)
    {
        printf("Error: memory allocation failed\n");
        return 1;
    }

    fscanf(fp, "<%99[^>]>", title); // read up to 99 characters until '>'
    printf("%s\n", title);

    free(title);
    fclose(fp);
    return 0;
}
