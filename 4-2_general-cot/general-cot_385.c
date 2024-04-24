#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char line[256];
    int livecells, alive_row, alive_column;

    fp = fopen("file.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    fgets(line, sizeof(line), fp);
    livecells = atoi(line);
    fprintf(stderr, "\n%i live cells\n", livecells);

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (sscanf(line, "%d %d", &alive_row, &alive_column) == 2) {
            fprintf(stderr, "\n Cell: (%i)(%i)", alive_row, alive_column);
        }
    }

    fclose(fp);
    return 0;
}
