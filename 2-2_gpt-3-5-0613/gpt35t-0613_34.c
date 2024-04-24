#include <stdio.h>
#include <string.h>

int main()
{
    char fInName[50];
    char fOutName[50];

    printf("Please type input file and output file:\n");
    scanf("%s %s", fInName, fOutName);

    if (strcmp(fInName, "") == 0 && strcmp(fOutName, "") == 0)
    {
        printf("Error: No file names entered.\n");
    }
    else if (strcmp(fInName, "") != 0 && strcmp(fOutName, "") == 0)
    {
        printf("Error: No output file name entered.\n");
    }
    else if (strcmp(fInName, "") == 0 && strcmp(fOutName, "") != 0)
    {
        printf("Error: No input file name entered.\n");
    }
    else
    {
        printf("Both file names entered.\n");
    }

    return 0;
}
