#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

int main(void)
{
    char teamname[32][30]; // 32 team names with max length of 30 characters each
    double teamscore[32]; // array to store team scores
    int n = 0;
    
    FILE* filein_ptr = fopen(FILEIN, "r");
    if (filein_ptr == NULL) {
        perror("Error opening input file");
        return 1;
    }

    while (n < 32 && fscanf(filein_ptr, "%29[^,],%lf\n", teamname[n], &teamscore[n]) == 2) {
        n++;
    }
    fclose(filein_ptr);

    FILE* fileout_ptr = fopen(FILEOUT, "w");
    if (fileout_ptr == NULL) {
        perror("Error opening output file");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fileout_ptr, "%s %f\n", teamname[i], teamscore[i]);
    }
    
    fclose(fileout_ptr);

    return 0;
}
