#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, b;
    char title[100]; // assuming title has a maximum length of 100 characters
    FILE *fp;

    fp = fopen("input2.txt", "r");
    if (fp == NULL)
    {
         printf ("Error: file cannot be found\n");
         return 1;
    }

    fscanf(fp, "<%d>\n<%d>", &m, &b);
    printf("%d\n%d\n", m, b);
    fscanf(fp, "\n<%99[^\n]>", title); // read string up to the newline character
    printf("%s\n", title);

    fclose(fp);
    return 0;
}
