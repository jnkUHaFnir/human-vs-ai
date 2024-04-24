#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"
#define MAX_TEAMS 32
#define MAX_TEAM_NAME_LENGTH 50

int main(void)
{
    double teamscore[MAX_TEAMS];
    char teamname[MAX_TEAMS][MAX_TEAM_NAME_LENGTH];
    int n = 0;
    FILE *filein_ptr;
    FILE *fileout_ptr;

    filein_ptr = fopen(FILEIN, "r");
    fileout_ptr = fopen(FILEOUT, "w");

    if (filein_ptr == NULL) {
        perror("Error opening input file");
        return 1;
    }
    if (fileout_ptr == NULL) {
        perror("Error opening output file");
        return 1;
    }

    while (fscanf(filein_ptr, "%49[^,],%lf\n", teamname[n], &teamscore[n]) == 2) {
        fprintf(fileout_ptr, "%s,%f\n", teamname[n], teamscore[n]);
        n++;
        if (n >= MAX_TEAMS) {
            break; // Prevents overflow if there are more than MAX_TEAMS teams
        }
    }

    fclose(filein_ptr);
    fclose(fileout_ptr);

    return 0;
}
