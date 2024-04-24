#include <stdio.h>
#include <stdlib.h>

#define MAX_TITLE_SIZE 100  // define maximum size for title string

int main()
{
    int m, b;
    char *title;
    FILE *fp;

    // allocate memory for title
    title = malloc(MAX_TITLE_SIZE);
    if(title == NULL) {
        printf("Failed to allocate memory for title\n");
        return 1;
    }

    fp = fopen("input2.txt", "r");
    if (fp == NULL)
    {
        printf ("Error: file cannot be found\n");
        // free allocated memory before returning
        free(title);
        return 1;
    }

    fscanf(fp, "<%d>\n<%d>", &m, &b);
    printf("%d\n%d", m, b);
    // make sure title is only read up to MAX_TITLE_SIZE - 1 characters to avoid overflow
    fscanf(fp, "<%99s>", title);

    printf("Title: %s\n", title);

    // free allocated memory after use
    free(title);

    fclose(fp);
    return 0;
}
