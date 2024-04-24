#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("file.txt", "r");

    char line[6]; // Make sure this is large enough to hold the longest possible line

    fgets(line, sizeof(line), fp);
    int livecells = atoi(line);
    fprintf(stderr, "\n%i live cells\n", livecells);

    while (fgets(line, sizeof(line), fp) != NULL) {
        int alive_row, alive_column;
        sscanf(line, "%d %d", &alive_row, &alive_column);

        fprintf(stderr, "\nCell: (%d)(%d)", alive_row, alive_column);
    }

    fclose(fp);

    return 0;
}
