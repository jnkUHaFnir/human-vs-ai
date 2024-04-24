#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

int main(void)
{
    // Define arrays to hold the team names and scores
    char teamnames[32][30];
    double teamscores[32];

    // Open the input file for reading
    FILE *filein_ptr = fopen(FILEIN, "r");
    if (filein_ptr == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Open the output file for writing
    FILE *fileout_ptr = fopen(FILEOUT, "w");
    if (fileout_ptr == NULL) {
        perror("Error opening output file");
        fclose(filein_ptr);
        return 1;
    }

    int n = 0;
    while (n < 32 && fscanf(filein_ptr, "%29[^,],%lf\n", teamnames[n], &teamscores[n]) == 2) {
        // Write the team name and score to the output file
        fprintf(fileout_ptr, "%s %f\n", teamnames[n], teamscores[n]);
        n++;
    }

    // Close the files
    fclose(filein_ptr);
    fclose(fileout_ptr);

    return 0;
}
