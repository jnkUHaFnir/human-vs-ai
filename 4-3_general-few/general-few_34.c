#include <stdio.h>
#include <string.h>

int main() {
    char fInName[50];
    char fOutName[50];

    printf("Please type input file, and output file (please type legibly): ");
    scanf("%49s %49s", fInName, fOutName);

    if (strlen(fInName) == 0 && strlen(fOutName) == 0) {
        printf("Error: File names not provided.\n");
    } else if (strlen(fInName) != 0 && strlen(fOutName) == 0) {
        printf("File found: %s\n", fInName);
    } else {
        printf("Both input and output files provided.\n");
    }

    return 0;
}
