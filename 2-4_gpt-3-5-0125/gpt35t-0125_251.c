for(x = 0; x < len; x++) {
    if(strcmp(laender[x], bundesland) == 0 && bewohner[x] >= anzahl) {
        char *zeile = (char*) malloc(100);
        if(zeile == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        sprintf(zeile, "Die Stadt %s hat %d Einwohner.", staedte[x], bewohner[x]);
        zeile_array[d] = zeile;   // putting it into array
        d++;
    }
}

write_file(zeile_array, d);

// Free allocated memory
for(int i = 0; i < d; i++) {
    free(zeile_array[i]);
}
