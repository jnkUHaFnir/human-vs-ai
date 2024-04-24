#include <stdio.h>
#include <string.h>

int main() {
    FILE *fin = NULL;
    FILE *fout = NULL;
    char fInName[50] = {0};
    char fOutName[50] = {0};
    char inputLine[100]; // Adjust size as needed

    printf("Please type input file, and output file please type legibly\n");

    // Read the whole line
    if (fgets(inputLine, sizeof(inputLine), stdin) != NULL) {
        // Try to extract two strings
        int numScanned = sscanf(inputLine, "%49s %49s", fInName, fOutName);
        if (numScanned < 2) {
            printf("Error: Insufficient input.\n");
            // Handle the error (e.g., return or ask again)
        } else {
            // Proceed with file opening, etc.
            printf("First file: %s, Second file: %s\n", fInName, fOutName);
            // You would continue with your file processing here
        }
    }
    return 0;
}
