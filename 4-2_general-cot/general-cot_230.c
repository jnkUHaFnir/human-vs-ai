#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

int main(void)
{
    char teamname[32][30];
    double teamscore[32];
    int n = 0;
    
    FILE *filein_ptr = fopen(FILEIN, "r");
    FILE *fileout_ptr = fopen(FILEOUT, "w");

    if (filein_ptr == NULL || fileout_ptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(filein_ptr, "%29[^,],%lf\n", teamname[n], &teamscore[n]) == 2) {
        fprintf(fileout_ptr, "%s %.2f\n", teamname[n], teamscore[n]);
        n++;
    }

    fclose(filein_ptr);
    fclose(fileout_ptr);

    return 0;
}
