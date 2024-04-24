#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // Include the string library for strtok

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

int main (void)
{
    char teamnames[32][30]; // Array to store team names
    double teamscores[32]; // Array to store team scores
    int n = 0;
    char line[100];
    
    FILE *filein_ptr;
    FILE *fileout_ptr;

    filein_ptr = fopen(FILEIN, "r");
    fileout_ptr = fopen(FILEOUT, "w");

    if (filein_ptr == NULL || fileout_ptr == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), filein_ptr) != NULL && n < 32) {
        char *token = strtok(line, ",");
        if (token != NULL) {
            strcpy(teamnames[n], token); // Copy team name to array
            token = strtok(NULL, ",");
            if (token != NULL) {
                teamscores[n] = atof(token); // Convert score to double and store in array
                fprintf(fileout_ptr, "%s    %f\n", teamnames[n], teamscores[n]); // Write to output file
                n++;
            }
        }
    }

    fclose(filein_ptr);
    fclose(fileout_ptr);

    return 0;
}
