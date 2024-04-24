#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

int main(void)
{
    double teamscore[32];
    char teamname[32][30];
    int n;
    FILE *filein_ptr;
    FILE *fileout_ptr;

    filein_ptr = fopen(FILEIN, "r");
    fileout_ptr = fopen(FILEOUT, "w");

    for (n = 0; n < 32; n++) {
        char line[100];
        fgets(line, sizeof line, filein_ptr);
        sscanf(line, "%[^,],%lf", teamname[n], &teamscore[n]); // Use sscanf to extract team name and score

        fprintf(fileout_ptr, "%s    %f\n", teamname[n], teamscore[n]);
    }

    fclose(filein_ptr);
    fclose(fileout_ptr);

    return 0;
}
