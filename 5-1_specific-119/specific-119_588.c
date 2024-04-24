#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

int main(void)
{
    double nfl[32][32], teamscore[32];
    char teamname[32][30]; // Assuming maximum 32 team names of 30 characters each
    char line[100]; // Assuming maximum line length in the file is 100 characters
    int n = 0;

    FILE* filein_ptr = fopen(FILEIN, "r");
    if (filein_ptr == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), filein_ptr) && n < 32) {
        char* token = strtok(line, ",");
        if (token != NULL) {
            strcpy(teamname[n], token);
            token = strtok(NULL, ",");
            if (token != NULL) {
                teamscore[n] = atof(token);
                n++;
            }
        }
    }

    fclose(filein_ptr);

    FILE* fileout_ptr = fopen(FILEOUT, "w");
    if (fileout_ptr == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fileout_ptr, "%s    %f\n", teamname[i], teamscore[i]);
    }

    fclose(fileout_ptr);

    return 0;
}
