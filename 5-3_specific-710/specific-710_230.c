#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_TEAMS 32
#define MAX_NAME_LENGTH 30
#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

int main(void)
{
    char teamname[MAX_TEAMS][MAX_NAME_LENGTH + 1]; // +1 for null terminator
    double teamscore[MAX_TEAMS];
    int n = 0;
    FILE *filein_ptr;
    FILE *fileout_ptr;

    filein_ptr = fopen(FILEIN, "r");
    fileout_ptr = fopen(FILEOUT, "w");

    // Check if files opened successfully
    if (filein_ptr == NULL || fileout_ptr == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    // Read team names and scores from the input file
    while (fscanf(filein_ptr, "%30[^,],%lf\n", teamname[n], &teamscore[n]) == 2 && n < MAX_TEAMS) {
        fprintf(fileout_ptr, "%s, %f\n", teamname[n], teamscore[n]);
        n++;
    }

    fclose(filein_ptr);
    fclose(fileout_ptr);

    return 0;
}
