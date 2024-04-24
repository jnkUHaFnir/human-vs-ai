int x = 0;
int d = 0;
char *zeile_array[50];

for (x = 0; x < 50; x++) {
    zeile_array[x] = (char*)malloc(100 * sizeof(char)); // Allocate memory for each entry in zeile_array
}

char zeile[100]; // Use an array instead of a pointer to prevent the memory issue

for (x = 0; x < len; x++) {
    if (strcmp(laender[x], bundesland) == 0 && bewohner[x] >= anzahl) {
        snprintf(zeile, 100, "Die Stadt %s hat %d Einwohner.", staedte[x], bewohner[x]);
        strncpy(zeile_array[d], zeile, 100); // Copy the content to zeile_array
        d++;
    }
}

write_file(zeile_array, d);

// Free the dynamically allocated memory
for (x = 0; x < 50; x++) {
    free(zeile_array[x]);
}
