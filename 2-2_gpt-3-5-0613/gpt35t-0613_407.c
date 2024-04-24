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
    printf("%d\n%d", m, b);

    title = malloc(sizeof(char) * 100);  // Change the size accordingly based on the maximum length of the string 

    fscanf(fp, "<%99[^\n]>%*c", title);  // Read up to 99 characters excluding newline

    fclose(fp);

    printf("\n%s", title);
    free(title);  // Free the memory allocated for the string

    return 0;
}