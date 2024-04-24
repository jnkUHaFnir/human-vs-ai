#include <stdio.h>
#include <string.h>

int main() {
    char fInName[50];
    char fOutName[50];

    printf("Please type input file and output file (please type legibly): ");
    scanf("%s %s", fInName, fOutName);

    if (fInName[0] == '\0' || fOutName[0] == '\0') {
        if (fInName[0] == '\0' && fOutName[0] == '\0') {
            printf("Error: Both input file and output file names are empty.\n");
        } else if (fOutName[0] == '\0') {
            printf("Error: Output file name is empty.\n");
        } else {
            printf("Error: Input file name is empty.\n");
        }
    } else {
        printf("File names provided.\n");
        // Add code to open and process files here
    }

    return 0;
}
