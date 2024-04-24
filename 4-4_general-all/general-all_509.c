#include <stdio.h>
#include <stdlib.h>

#define MAX_TITLE_LENGTH 100

int main()
{
    int m, b;
    char title[MAX_TITLE_LENGTH]; // Allocate memory for the title
    
    FILE *fp = fopen("input2.txt", "r");
    if (fp == NULL)
    {
        printf("Error: file cannot be found\n");
        return 1;
    }

    if (fscanf(fp, "<%d>\n<%d>", &m, &b) != 2) {
        printf("Error reading values\n");
        fclose(fp);
        return 1;
    }
    
    printf("%d\n%d", m, b);
    
    if (fscanf(fp, "<%99[^>]>", title) != 1) {
        printf("Error reading title\n");
        fclose(fp);
        return 1;
    }

    printf("\n%s", title);

    fclose(fp);
    return 0;
}
