#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // For atoi function

#define FILEIN "data.csv"
#define FILEOUT "matrix.csv"

int main(void)
{
    char teamname[32][30];
    int teamscore[32];
    int n = 0;
    
    FILE* filein_ptr = fopen(FILEIN, "r");
    FILE* fileout_ptr = fopen(FILEOUT, "w");

    if (filein_ptr == NULL || fileout_ptr == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    while (fscanf(filein_ptr, "%29[^,],%d ", teamname[n], &teamscore[n]) == 2) {
        fprintf(fileout_ptr, "%s    %d\n", teamname[n], teamscore[n]);
        n++;
    }

    fclose(filein_ptr);
    fclose(fileout_ptr);

    return 0;
}
