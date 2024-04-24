#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

int main(void)
{
    double nfl[32], teamscore[32];
    char teamname[32][30];
    int n = 0;
    
    FILE* filein_ptr = fopen(FILEIN, "r");
    FILE* fileout_ptr = fopen(FILEOUT, "w");

    if (filein_ptr == NULL || fileout_ptr == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    char line[50]; // assuming max line length is 50 characters
    while (fgets(line, sizeof(line), filein_ptr)) {
        char* token = strtok(line, ",");
        if (token) {
            strcpy(teamname[n], token);
        }

        token = strtok(NULL, ",");
        if (token) {
            teamscore[n] = atof(token);
            n++;
        }
    }

    for (int i = 0; i < n; i++) {
        fprintf(fileout_ptr, "%s    %f\n", teamname[i], teamscore[i]);
    }

    fclose(filein_ptr);
    fclose(fileout_ptr);

    return 0;
}
