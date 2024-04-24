char *title;
#define MAX_TITLE_LENGTH 256
char title[MAX_TITLE_LENGTH];
char *title = malloc(sizeof(char) * (MAX_TITLE_LENGTH));
if(title == NULL)
{
    printf("Unable to allocate memory for title\n");
    fclose(fp);
    return 1;
}
fscanf(fp, "<%255s>", title);
free(title);
#include <stdio.h>
#include <stdlib.h>

#define MAX_TITLE_LENGTH 256

int main()
{
    int m, b;
    char *title = malloc(sizeof(char) * (MAX_TITLE_LENGTH));
    if(title == NULL)
    {
        printf("Unable to allocate memory for title\n");
        return 1;
    }

    FILE *fp = fopen("input2.txt", "r");
    if (fp == NULL)
    {
        printf("Error: file cannot be found\n");
        free(title); // Clean up memory before returning
        return 1;
    }

    fscanf(fp, "<%d>\n<%d>", &m, &b);
    printf("%d\n%d\n", m, b);
    fscanf(fp, "<%255s>", title); // Assuming title won't be larger than 255 characters
    
    printf("%s\n", title); // Don't forget to print the title if you want to see it

    fclose(fp);
    free(title); // Clean up dynamically allocated memory
    return 0;
}
