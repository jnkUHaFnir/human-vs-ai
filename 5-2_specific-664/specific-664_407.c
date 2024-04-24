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

    // Dynamically allocate memory for title
    title = (char*)malloc(100 * sizeof(char)); // Assuming max string length is 100 characters
    if (title == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    fscanf(fp, "<%99[^\n]>", title); // Read up to 99 characters (avoid buffer overflow)

    printf("%s\n", title);

    free(title); // Free dynamically allocated memory
    fclose(fp);
    return 0;
}
