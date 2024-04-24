#include <stdio.h>
#include <string.h> // Include string library for strcmp function

int main() {
    char fInName[50];
    char fOutName[50];

    printf("Please type input file and output file (please type legibly): ");
    scanf("%s %s", fInName, fOutName);

    if (fInName[0] == '\0' && fOutName[0] == '\0') {
        printf("Error: No file names provided.\n");
    } else if (fInName[0] != '\0' && fOutName[0] == '\0') {
        printf("Error: Cannot open output file %s.\n", fOutName);
    } else {
        printf("Files found: %s and %s\n", fInName, fOutName);
    }

    return 0;
}
