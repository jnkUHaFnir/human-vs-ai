#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"
#define MAX_NAME_LENGTH 30
#define MAX_TEAMS 32

int main(void)
{
    double teamscore[MAX_TEAMS];
    char teamname[MAX_TEAMS][MAX_NAME_LENGTH];
    int n;
    FILE* filein_ptr;
    FILE* fileout_ptr;

    filein_ptr = fopen(FILEIN, "r");
    if (filein_ptr == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    fileout_ptr = fopen(FILEOUT, "w");
    if (fileout_ptr == NULL) {
        printf("Error opening output file.\n");
        fclose(filein_ptr);
        return 1;
    }

    for (n = 0; n < MAX_TEAMS; n++) {
        fscanf(filein_ptr, "%[^,], %lf\n", teamname[n], &teamscore[n]);
        fprintf(fileout_ptr, "%s, %f\n", teamname[n], teamscore[n]);
    }

    fclose(filein_ptr);
    fclose(fileout_ptr);

    return 0;
}
