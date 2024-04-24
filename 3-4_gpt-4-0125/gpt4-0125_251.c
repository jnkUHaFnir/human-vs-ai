for(x = 0; x < len; x++) {
    if(strcmp(laender[x], bundesland) == 0 && bewohner[x] >= anzahl) {
        char *zeile = malloc(100); // Allocate memory for each string
        if (zeile == NULL) {
            // Handle memory allocation failure
            perror("Failed to allocate memory for zeile");
            exit(1);
        }
        sprintf(zeile, "Die Stadt %s hat %d Einwohner.", staedte[x], bewohner[x]);
        zeile_array[d] = zeile; // Store the pointer in the array
        d++;
    }
}
// After write_file(zeile_array, d);
for (int i = 0; i < d; i++) {
    free(zeile_array[i]);
}
