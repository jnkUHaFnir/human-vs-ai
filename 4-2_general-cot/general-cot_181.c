#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

int main(void)
{
    char teamname[32][30]; // 32 teams, each with a maximum of 30 characters
    double teamscore[32];
    int n = 0;
    FILE *filein_ptr;
    FILE *fileout_ptr;

    filein_ptr = fopen(FILEIN, "r");
    fileout_ptr = fopen(FILEOUT, "w");

    if (filein_ptr == NULL || fileout_ptr == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fscanf(filein_ptr, "%29[^,],%lf\n", teamname[n], &teamscore[n]) == 2 && n < 32) {
        fprintf(fileout_ptr, "%s %.2f\n", teamname[n], teamscore[n]);
        n++;
    }

    fclose(filein_ptr);
    fclose(fileout_ptr);

    return 0;
}
