#include <stdio.h>
#include <string.h>

int main() {
    char fInName[50];
    char fOutName[50];

    printf("Please type input file, and output file please type legibly\n");
    if (scanf("%s %s", fInName, fOutName) != 2) {
        printf("No input provided.\n");
    }
    else {
        if (strcmp(fInName, fOutName) == 0) {
            printf("Error: Input and output file can't have the same name.\n");
        }
        else {
            printf("Files found: %s and %s\n", fInName, fOutName);
        }
    }

    return 0;
}
