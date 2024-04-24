#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char line[20];
    int livecells, alive_row, alive_column;

    fp = fopen("file.txt", "r");
    if (!fp) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    if (!fgets(line, sizeof(line), fp)) {
        fprintf(stderr, "Error reading live cell count\n");
        return 1;
    }
    livecells = atoi(line);
    fprintf(stderr, "%d live cells\n", livecells);

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (sscanf(line, "%d %d", &alive_row, &alive_column) != 2) {
            fprintf(stderr, "Error reading cell coordinates\n");
            break;
        }

        fprintf(stderr, "Cell: (%d)(%d)\n", alive_row, alive_column);
    }

    fclose(fp);
    return 0;
}
