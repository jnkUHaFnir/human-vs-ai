#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_TEAMS 32
#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

int main(void)
{
    double teamscore[MAX_TEAMS];
    char teamname[MAX_TEAMS][30]; // 2D array to store team names
    int n = 0;
    FILE *filein_ptr;
    FILE *fileout_ptr;

    filein_ptr = fopen(FILEIN, "r");
    fileout_ptr = fopen(FILEOUT, "w");

    if (filein_ptr == NULL || fileout_ptr == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fscanf(filein_ptr, "%29[^,], %lf\n", teamname[n], &teamscore[n]) == 2 && n < MAX_TEAMS) {
        fprintf(fileout_ptr, "%s    %f\n", teamname[n], teamscore[n]);
        n++;
    }

    fclose(filein_ptr);
    fclose(fileout_ptr);

    return 0;
}
