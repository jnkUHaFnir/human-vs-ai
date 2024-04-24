#include <stdio.h>
#include <string.h>

int main() {
    FILE *fin;
    FILE *fout;
    char fInName[50];
    char fOutName[50];

    printf("Please type input file and output file names (separated by space): ");
    if (scanf("%49s %49s", fInName, fOutName) == 2) {
        fin = fopen(fInName, "r");
        fout = fopen(fOutName, "w");

        if (fin == NULL || fout == NULL) {
            printf("Error: Cannot open input or output file\n");
        } else {
            printf("Files found\n");

            // Continue with processing the files here
        }

        if (fin) {
            fclose(fin); // Closing input file if opened
        }
        if (fout) {
            fclose(fout); // Closing output file if opened
        }
    } else {
        printf("Error: Input file name and/or output file name not provided\n");
    }

    return 0;
}
