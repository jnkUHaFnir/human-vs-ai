#define MAX_LINE_LENGTH 10  // Define a maximum line length for fgets

char line[MAX_LINE_LENGTH];
int livecells, alive_row, alive_column;

if (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
    livecells = atoi(line);
    fprintf(stderr, "\n%i live cells\n", livecells);

    for (int i = 0; i < livecells; i++) {
        if (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
            sscanf(line, "%d %d", &alive_row, &alive_column);
            fprintf(stderr, "\n Cell: (%d)(%d)", alive_row, alive_column);
        }
    }
}
