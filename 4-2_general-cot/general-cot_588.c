#include <stdio.h>
#include <string.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

#define MAX_TEAMS 32
#define MAX_NAME_LENGTH 30

int main(void) {
    char teamname[MAX_TEAMS][MAX_NAME_LENGTH];
    double teamscore[MAX_TEAMS];
    int n = 0;

    FILE* filein_ptr = fopen(FILEIN, "r");
    if (filein_ptr == NULL) {
        perror("Error opening input file");
        return 1;
    }

    FILE* fileout_ptr = fopen(FILEOUT, "w");
    if (fileout_ptr == NULL) {
        perror("Error opening output file");
        fclose(filein_ptr);
        return 1;
    }

    while (n < MAX_TEAMS && fscanf(filein_ptr, "%29[^,],%lf\n", teamname[n], &teamscore[n]) == 2) {
        fprintf(fileout_ptr, "%s, %.2f\n", teamname[n], teamscore[n]);
        n++;
    }

    fclose(filein_ptr);
    fclose(fileout_ptr);

    return 0;
}
