// Inside the main function
for (x = 0; x < len; x++)
{
    if (strcmp(laender[x], bundesland) == 0 && bewohner[x] >= anzahl)
    {
        char *zeile = malloc(100); // allocate memory for each string
        if (zeile == NULL) {
            perror("Memory allocation error");
            exit(1);
        }

        sprintf(zeile, "Die Stadt %s hat %d Einwohner.", staedte[x], bewohner[x]);
        zeile_array[d] = zeile; // storing the address of the newly allocated memory
        d++;
    }
}

// After processing the loop, write to the file and free dynamically allocated memory
write_file(zeile_array, d);
for (int i = 0; i < d; i++) {
    free(zeile_array[i]); // free each dynamically allocated string
}
