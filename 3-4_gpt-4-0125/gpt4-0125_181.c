// Assuming each team name won't exceed 29 characters
// and assuming we don't deal with more than 32 teams.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"
#define MAX_TEAMS 32
#define TEAM_NAME_MAX_LENGTH 30 // Assuming this includes the null terminator

int main(void)
{
    double teamscore[MAX_TEAMS];
    char teamname[TEAM_NAME_MAX_LENGTH];
    int n = 0; // Using 0-based indexing
    FILE* filein_ptr;
    FILE* fileout_ptr;

    filein_ptr = fopen(FILEIN, "r");
    fileout_ptr = fopen(FILEOUT, "w");

    if (!filein_ptr || !fileout_ptr) {
        perror("Error opening files");
        return 1;
    }

    while (fscanf(filein_ptr, "%29[^,],%lf\n", teamname, &teamscore[n]) == 2) {
        fprintf(fileout_ptr, "%s, %f\n", teamname, teamscore[n]);
        n++;
        // Prevent reading more teams than the array can hold.
        if (n >= MAX_TEAMS) break;
    }

    fclose(filein_ptr);
    fclose(fileout_ptr);

    return 0;
}
