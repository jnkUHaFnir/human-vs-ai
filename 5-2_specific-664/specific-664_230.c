#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_TEAMS 32
#define MAX_TEAM_NAME_LENGTH 30
#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

int main(void)
{
    char teamname[MAX_TEAMS][MAX_TEAM_NAME_LENGTH];
    double teamscore[MAX_TEAMS];
    int n = 0;
    
    FILE *filein_ptr = fopen(FILEIN, "r");
    FILE *fileout_ptr = fopen(FILEOUT, "w");
    
    if (filein_ptr == NULL || fileout_ptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(filein_ptr, "%[^,],%lf\n", teamname[n], &teamscore[n]) == 2 && n < MAX_TEAMS) {
        fprintf(fileout_ptr, "%s    %f\n", teamname[n], teamscore[n]);
        n++;
    }
    
    fclose(filein_ptr);
    fclose(fileout_ptr);

    return 0;
}
