#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"
#define MAX_TEAMS 32
#define TEAM_NAME_LEN 50

int main(void)
{
    double teamscore[MAX_TEAMS];
    char teamname[MAX_TEAMS][TEAM_NAME_LEN];
    int n; // Counter for teams
    FILE *filein_ptr;
    FILE *fileout_ptr;

    // Open files and check for errors
    filein_ptr = fopen(FILEIN, "r");
    if (!filein_ptr) {
        perror("Error opening input file");
        return 1;
    }

    fileout_ptr = fopen(FILEOUT, "w");
    if (!fileout_ptr) {
        perror("Error opening output file");
        fclose(filein_ptr);
        return 1;
    }

    // Read and save team names and scores into separate arrays
    n = 0;
    while (fscanf(filein_ptr, "%[^,],%lf\n", teamname[n], &teamscore[n]) == 2 && n < MAX_TEAMS) {
        n++;
    }

    // Check for possible input error
    if (!feof(filein_ptr)) {
        perror("File read error");
        fclose(filein_ptr);
        fclose(fileout_ptr);
        return 1;
    }

    // Writing team names and scores to the output file
    for (int i = 0; i < n; i++) {
        fprintf(fileout_ptr, "%s,%f\n", teamname[i], teamscore[i]);
    }

    // Close opened files
    fclose(filein_ptr);
    fclose(fileout_ptr);

    return 0;
}
