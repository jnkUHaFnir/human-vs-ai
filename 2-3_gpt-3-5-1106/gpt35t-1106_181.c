#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

int main (void)
{
    char teamname[32][30];
    double teamscore[32];
    int n = 0;
    FILE *filein_ptr;
    FILE *fileout_ptr;

    filein_ptr = fopen (FILEIN, "r");
    fileout_ptr = fopen (FILEOUT, "w");

    while (fscanf(filein_ptr, "%[^,],%lf\n", teamname[n], &teamscore[n]) == 2) {
        fprintf(fileout_ptr, "%s    %f\n", teamname[n], teamscore[n]);
        n++;
    }

    fclose(filein_ptr);
    fclose(fileout_ptr);

    return 0;
}
