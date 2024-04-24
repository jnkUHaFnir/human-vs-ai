#include <stdio.h>
#include <string.h>

int main() {
    char fInName[50];
    char fOutName[50];

    printf("please type input file and output file: ");
    fgets(fInName, sizeof(fInName), stdin);
    
    // Remove newline character from fgets
    fInName[strcspn(fInName, "\n")] = '\0';

    fgets(fOutName, sizeof(fOutName), stdin);
    fOutName[strcspn(fOutName, "\n")] = '\0';
    
    if (fInName[0] == '\0' || fOutName[0] == '\0') {
        printf("Error: File names cannot be empty.\n");
    } 
    else if (strcmp(fInName, fOutName) == 0) {
        printf("Error: Input file name and output file name cannot be the same.\n");
    }
    else {
        printf("Files found: %s, %s\n", fInName, fOutName);
        // Add file handling logic here
    }

    return 0;
}
