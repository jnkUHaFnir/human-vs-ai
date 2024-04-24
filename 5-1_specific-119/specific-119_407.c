#include <stdio.h>
#include <stdlib.h>

#define MAX_TITLE_LENGTH 100

int main()
{
    int m, b;
    char title[MAX_TITLE_LENGTH];
    FILE *fp;

    fp = fopen("input2.txt", "r");
    if (fp == NULL)
    {
         printf ("Error: file cannot be found\n");
         return 1;
    }

    fscanf(fp, "<%d>\n<%d>", &m, &b);
    printf("%d\n%d", m, b);
    
    fscanf(fp, "<%99[^>]>", title); // Read up to 99 characters (leave 1 for null terminator)

    fclose(fp);
    return 0;
}
