#include <stdio.h>
#include <string.h>

int main()
{
    char fInName[50];
    char fOutName[50];

    printf("Please type input file and output file names: ");
    fgets(fInName, 50, stdin); // Read input including spaces
    fgets(fOutName, 50, stdin);

    // Remove newline characters from the input
    fInName[strcspn(fInName, "\n")] = '\0';
    fOutName[strcspn(fOutName, "\n")] = '\0';

    if (fInName[0] == '\0' && fOutName[0] == '\0')
    {
        printf("Error: Empty input filenames.\n");
    }
    else if (fInName[0] != '\0' && fOutName[0] == '\0')
    {
        printf("Error: Input file '%s' specified but no output file.\n", fInName);
    }
    else
    {
        printf("Input file: %s, Output file: %s\n", fInName, fOutName);
    }

    return 0;
}
