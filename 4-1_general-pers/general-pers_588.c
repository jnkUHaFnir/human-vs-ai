#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

#define MAX_TEAMS 32
#define MAX_NAME_LEN 30

int main(void)
{
    char teamnames[MAX_TEAMS][MAX_NAME_LEN];  // Array to store team names
    double teamscores[MAX_TEAMS];  // Array to store team scores
    int n = 0;
    FILE* filein_ptr;
    FILE* fileout_ptr;

    // Open input and output files
    filein_ptr = fopen(FILEIN, "r");
    fileout_ptr = fopen(FILEOUT, "w");

    // Loop to read data from input file
    while (n < MAX_TEAMS && fscanf(filein_ptr, "%[^,],%lf\n", teamnames[n], &teamscores[n]) == 2) {
        fprintf(fileout_ptr, "%s    %f\n", teamnames[n], teamscores[n]);
        n++;
    }

    // Close input and output files
    fclose(filein_ptr);
    fclose(fileout_ptr);

    return 0;
}
