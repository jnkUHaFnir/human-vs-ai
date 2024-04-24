int x = 0;
int d = 0;

// Allocate memory for zeile_array
char *zeile_array[50];

for (x = 0; x < len; x++) {
    if (strcmp(laender[x], bundesland) == 0 && bewohner[x] >= anzahl) {
        // Allocate memory for each line in zeile_array
        char *zeile = (char *) malloc(100); // moved allocation inside loop

        sprintf(zeile, "Die Stadt %s hat %d Einwohner.", staedte[x], bewohner[x]);
        zeile_array[d] = zeile;
        d = d + 1;
    }
}

write_file(zeile_array, d);

// Free memory for each line in zeile_array
for (int i = 0; i < d; i++) {
    free(zeile_array[i]);
}
