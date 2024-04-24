for (x = 0; x < len; x++) {
    if (strcmp(laender[x], bundesland) == 0 && bewohner[x] >= anzahl) {
        char *zeile = malloc(100); // Allocate memory for each string
        if (zeile == NULL) {
            perror("Memory allocation failed");
            exit(1);
        }

        sprintf(zeile, "Die Stadt %s hat %d Einwohner.", staedte[x], bewohner[x]);
        zeile_array[d] = zeile; // Store the allocated string pointer in zeile_array
        d = d + 1;
    }
}
