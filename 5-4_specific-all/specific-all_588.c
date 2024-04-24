#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

#define MAX_TEAMS 32
#define MAX_NAME_LENGTH 30

int main (void)
{
    char teamname[MAX_TEAMS][MAX_NAME_LENGTH];
    double teamscore[MAX_TEAMS];
    int n = 0;
    
    FILE *filein_ptr;
    FILE *fileout_ptr;

    filein_ptr = fopen(FILEIN, "r");
    fileout_ptr = fopen(FILEOUT, "w");

    if (filein_ptr == NULL || fileout_ptr == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    while (fscanf(filein_ptr, "%29[^,],%lf", teamname[n], &teamscore[n]) == 2) {
        fprintf(fileout_ptr, "%s    %.2f\n", teamname[n], teamscore[n]);
        n++;
        if (n >= MAX_TEAMS) {
            printf("Reached maximum number of teams.\n");
            break;
        }
    }

    fclose(filein_ptr);
    fclose(fileout_ptr);

    return 0;
}
