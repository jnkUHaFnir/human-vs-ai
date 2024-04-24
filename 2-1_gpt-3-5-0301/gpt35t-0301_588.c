#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

int main (void)
{
    double nfl[32][32], teamscore[32];
    char teamname[32][30]; // Use a 2D array to store team names
    char line[100];
    int n = 0;
    FILE *filein_ptr;
    FILE *fileout_ptr;

    filein_ptr = fopen (FILEIN, "r");
    fileout_ptr = fopen (FILEOUT, "w");

    // Read in each line of the input file
    while (fgets(line, sizeof(line), filein_ptr)) {
        // Use strtok to separate the team name and score
        char *team = strtok(line, ",");
        double score = atof(strtok(NULL, ",\n"));

        // Store the team name and score in separate arrays
        strcpy(teamname[n], team);
        teamscore[n] = score;

        // Write the team name and score to the output file
        fprintf(fileout_ptr, "%s,%.1f\n", teamname[n], teamscore[n]);

        n++; // Increment the index for the arrays
    }

    fclose (filein_ptr);
    fclose (fileout_ptr);

    return 0;
}