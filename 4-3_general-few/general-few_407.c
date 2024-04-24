#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, b;
    char* title;
    FILE* fp;

    fp = fopen("input2.txt", "r");
    if (fp == NULL)
    {
        printf("Error: file cannot be found\n");
        return 1;
    }

    fscanf(fp, "<%d>\n<%d>", &m, &b);
    printf("%d\n%d", m, b);

    // Allocate memory for the title
    title = (char*)malloc(100 * sizeof(char)); // Allocating memory for a maximum of 100 characters

    fscanf(fp, "<%99[^>]>", title); // Read up to 99 characters until '>'
    
    printf("\n%s\n", title);
    
    // Free memory after use
    free(title);

    fclose(fp);
    return 0;
}
