#include <stdio.h>
#include <stdlib.h>

#define MAX_TITLE_SIZE 1000

int main()
{
    int m, b;
    char title[MAX_TITLE_SIZE];
    FILE *fp;

    fp = fopen("input2.txt", "r");
    if (fp == NULL)
    {
         printf ("Error: file cannot be found\n");
         return 1;
    }

    fscanf(fp, "<%d>\n<%d>", &m, &b);
    printf("%d\n%d", m, b);
    fscanf(fp, "<%999[^>]>", title); // Use 999 instead of 1000 to leave room for null-terminator

    fclose(fp);
    return 0;
}
