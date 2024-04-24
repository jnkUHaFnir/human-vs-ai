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
    title = (char*)malloc(256 * sizeof(char)); // Assuming title won't be longer than 255 characters
    if (title == NULL) {
        // Memory allocation failed
        printf("Error: Memory allocation failed\n");
        fclose(fp); // Cleanup: close the file before exiting
        return 1;
    }

    // Now safely attempt to read the title
    if (fscanf(fp, " %255[^\n]", title) == 1) {
        // Read successfully, now you can use `title`
        printf("%s\n", title);
    } else {
        // Handle read error or case where the expected format is not found
        printf("Error or no title to read\n");
    }

    free(title); // Cleanup: free allocated memory
    fclose(fp); // Cleanup: close the file
    return 0;
}
