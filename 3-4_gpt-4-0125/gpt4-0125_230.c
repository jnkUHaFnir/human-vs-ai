#include <stdio.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"
#define MAX_TEAMS 32
#define MAX_NAME_LEN 32

int main(void) {
    // Adjusted the teamname to hold multiple names, each up to 31 characters + null terminator.
    char teamname[MAX_TEAMS][MAX_NAME_LEN];
    double teamscore[MAX_TEAMS];  // Array to hold scores
    int teamCount = 0;  // Counter for the number of teams read.
    FILE *filein_ptr;
    FILE *fileout_ptr;
    
    filein_ptr = fopen(FILEIN, "r");
    fileout_ptr = fopen(FILEOUT, "w");
    
    if (!filein_ptr || !fileout_ptr) {
        printf("Error in opening file.\n");
        return 1;
    }

    while(fscanf(filein_ptr, "%[^,],%lf\n", teamname[teamCount], &teamscore[teamCount]) == 2) {
        // As long as we can read a string and a double in the expected format,
        // write to the file and increment the team count.
        fprintf(fileout_ptr, "%s, %f\n", teamname[teamCount], teamscore[teamCount]);
        teamCount++;

        // Check to avoid exceeding array boundaries.
        if (teamCount >= MAX_TEAMS) break;
    }

    fclose(filein_ptr);
    fclose(fileout_ptr);
    
    printf("Done processing %d teams.\n", teamCount);

    return 0;
}
