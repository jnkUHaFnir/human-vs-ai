#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

#define MAX_TEAMS 100
#define MAX_NAME_LEN 30

int main (void)
{
    double teamscore[MAX_TEAMS];
    char teamname[MAX_TEAMS][MAX_NAME_LEN];
    int n = 0;
    FILE *filein_ptr;
    FILE *fileout_ptr;

    filein_ptr = fopen (FILEIN, "r");
    if (filein_ptr == NULL) {
        printf("Error: Cannot open file %s\n", FILEIN);
        return 1;
    }

    fileout_ptr = fopen (FILEOUT, "w");
    if (fileout_ptr == NULL) {
        printf("Error: Cannot open file %s\n", FILEOUT);
        return 1;
    }

    while (fscanf (filein_ptr, "%[^,],%lf\n", teamname[n], &teamscore[n]) != EOF) {
        fprintf (fileout_ptr, "%s,%f\n", teamname[n], teamscore[n]);
        n++;
    }

    fclose (filein_ptr);
    fclose (fileout_ptr);

    return 0;
}
