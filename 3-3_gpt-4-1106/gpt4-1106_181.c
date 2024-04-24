#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"
#define MAX_TEAMS 32
#define MAX_NAME_LENGTH 50  // Adjust this if team names can be longer

int main(void)
{
    double teamscore[MAX_TEAMS];
    char teamname[MAX_TEAMS][MAX_NAME_LENGTH];
    int n;
    FILE *filein_ptr;
    FILE *fileout_ptr;
    
    filein_ptr = fopen(FILEIN, "r");
    fileout_ptr = fopen(FILEOUT, "w");
    
    if (!filein_ptr || !fileout_ptr) {
        perror("Error opening file");
        return 1;
    }

    for (n = 0; n < MAX_TEAMS && !feof(filein_ptr); n++) {
        if (fscanf(filein_ptr, "%49[^,],%lf", teamname[n], &teamscore[n]) == 2) {
            // Writing each team name and score to the output file
            fprintf(fileout_ptr, "%s, %f\n", teamname[n], teamscore[n]);
        }
    }

    fclose(filein_ptr);
    fclose(fileout_ptr);

    return 0;
}
