#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

int main(void) {
    char teamname[32][30];
    double teamscore[32];
    int n = 0;

    FILE *filein_ptr;
    FILE *fileout_ptr;

    filein_ptr = fopen(FILEIN, "r");
    if (!filein_ptr) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read each line from the input file
    while (fscanf(filein_ptr, "%[^,],%lf\n", teamname[n], &teamscore[n]) == 2) {
        n++;
        if (n >= 32) {
            printf("Exceeded maximum number of teams.\n");
            break;
        }
    }
    fclose(filein_ptr);

    fileout_ptr = fopen(FILEOUT, "w");
    if (!fileout_ptr) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Write the team names and scores to the output file
    for (int i = 0; i < n; i++) {
        fprintf(fileout_ptr, "%s, %f\n", teamname[i], teamscore[i]);
    }

    fclose(fileout_ptr);

    return 0;
}
