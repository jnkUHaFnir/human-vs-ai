#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, b;
    char *title = (char*)malloc(100*sizeof(char));
    FILE *fp;

    fp = fopen("input2.txt", "r");
    if (fp == NULL)
    {
         printf ("Error: file cannot be found\n");
         return 1;
    }

    fscanf(fp, "<%d>\n<%d>", &m, &b);
    printf("%d\n%d", m, b);
    fscanf(fp, "<%s>", title);

    fclose(fp);
    free(title); // Don't forget to free the memory after you're done using it
    return 0;
}
