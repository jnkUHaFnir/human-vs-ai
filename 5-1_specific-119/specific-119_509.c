#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, b;
    char title[100]; // Allocate memory for title
    FILE *fp;

    fp = fopen("input2.txt", "r");
    if (fp == NULL)
    {
         printf ("Error: file cannot be found\n");
         return 1;
    }

    fscanf(fp, "<%d>\n<%d>", &m, &b);
    printf("%d\n%d", m, b);
    fscanf(fp, "<%99[^>]>", title); // Read up to 99 characters until '>' character is encountered

    fclose(fp);
    return 0;
}
