#include <stdio.h>
#include <stdlib.h>

#define MAX_TITLE_LENGTH 100 // Define a maximum length for the title string

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

    title = (char*)malloc(MAX_TITLE_LENGTH * sizeof(char)); // Allocate memory for the title string
    if(title == NULL)
    {
        printf("Error: Memory allocation failed\n");
        return 1;
    }

    if(fscanf(fp, "<%99[^>]>", title) == 1) // Read up to 99 characters into title, stopping before '>'
    {
        printf("Title: %s\n", title);
    }
    else
    {
        printf("Error reading title from file\n");
    }

    free(title); // Free the allocated memory for title
    fclose(fp);
    return 0;
}
