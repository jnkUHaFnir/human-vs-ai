#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("file.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    char line[255]; // Assuming a max line length of 255 characters
    int livecells, alive_row, alive_column;
    
    if (fgets(line, sizeof(line), fp) != NULL) {
        livecells = atoi(line);
        fprintf(stderr, "\n%i live cells\n", livecells);
    }
    
    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%i %i", &alive_row, &alive_column);
        fprintf(stderr, "\nCell: (%i)(%i)", alive_row, alive_column);
    }
    
    fclose(fp);
    return 0;
}
