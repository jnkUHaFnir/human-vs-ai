#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

#define MAX_TEAMS 32

int main(void)
{
    char teamnames[MAX_TEAMS][30];
    double teamscores[MAX_TEAMS];
    int n = 0;

    FILE *filein_ptr;
    FILE *fileout_ptr;

    filein_ptr = fopen(FILEIN, "r");
    fileout_ptr = fopen(FILEOUT, "w");

    if (filein_ptr == NULL || fileout_ptr == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    while (fscanf(filein_ptr, "%29[^,],%lf", teamnames[n], &teamscores[n]) == 2) {
        fprintf(fileout_ptr, "%s    %f\n", teamnames[n], teamscores[n]);
        n++;

        if (n >= MAX_TEAMS) {
            printf("Exceeded maximum number of teams.\n");
            break;
        }
    }

    fclose(filein_ptr);
    fclose(fileout_ptr);

    return 0;
}
