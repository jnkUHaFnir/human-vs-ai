#include <stdio.h>
#include <string.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

int main(void) {
    double nfl[32], teamscore[32];
    char teamname[32][30];
    int n = 0;
    FILE *filein_ptr;
    FILE *fileout_ptr;

    filein_ptr = fopen(FILEIN, "r");

    while (fscanf(filein_ptr, "%[^,],%lf\n", teamname[n], &teamscore[n]) == 2) {
        n++;
    }

    fclose(filein_ptr);

    fileout_ptr = fopen(FILEOUT, "w");

    for (int i = 0; i < n; i++) {
        fprintf(fileout_ptr, "%s,%f\n", teamname[i], teamscore[i]);
    }

    fclose(fileout_ptr);

    return 0;
}
