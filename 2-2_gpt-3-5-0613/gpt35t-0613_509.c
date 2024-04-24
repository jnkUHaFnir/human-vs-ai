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

    // Allocate memory for the title variable
    title = (char*)malloc(sizeof(char) * 100); // Assuming a maximum string length of 100 characters

    fscanf(fp, "<%s>", title);

    fclose(fp);
    return 0;
}
free(title);
