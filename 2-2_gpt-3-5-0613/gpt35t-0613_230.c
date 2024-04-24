#include <stdio.h>
#include <string.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

int main(void) {
    char teamname[32][30];
    double teamscore[32];
    int n = 0;

    // Open the input file
    FILE *filein_ptr = fopen(FILEIN, "r");
    if (filein_ptr == NULL) {
        printf("Failed to open the file %s\n", FILEIN);
        return 1;
    }

    // Read the file line by line
    char line[64];
    while (fgets(line, sizeof(line), filein_ptr)) {
        // Split the line into team name and score using strtok function
        char *token = strtok(line, ",");
        if (token == NULL) {
            continue;  // Skip empty lines
        }

        // Copy the team name into the teamname array
        strncpy(teamname[n], token, sizeof(teamname[n]) - 1);
        teamname[n][sizeof(teamname[n]) - 1] = '\0';

        // Get the next token and convert it to a double (team score)
        token = strtok(NULL, ",");
        if (token == NULL) {
            continue;  // Skip lines that don't contain both team name and score
        }
        teamscore[n] = atof(token);

        n++;  // Increment n for the next team
    }

    // Close the input file
    fclose(filein_ptr);

    // Open the output file
    FILE *fileout_ptr = fopen(FILEOUT, "w");
    if (fileout_ptr == NULL) {
        printf("Failed to open the file %s\n", FILEOUT);
        return 1;
    }

    // Write the team names and scores into the output file
    for (int i = 0; i < n; i++) {
        fprintf(fileout_ptr, "%s    %.2f\n", teamname[i], teamscore[i]);
    }

    // Close the output file
    fclose(fileout_ptr);

    return 0;
}
