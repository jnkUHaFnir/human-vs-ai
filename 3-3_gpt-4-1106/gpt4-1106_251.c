char *zeile;
zeile=(char*) malloc(100); //allocating memory
sprintf(zeile, "Die Stadt %p hat %d Einwohner.",staedte[x],bewohner[x]);
zeile_array[d]=zeile;   // putting it into array
free(zeile);
int main(int argc, char **argv) {
    // ... same as before

    char *zeile_array[MAX_LAENGE_ARR];  // Assuming MAX_LAENGE_ARR as a practical limit for zeile_array size
    int d = 0;

    for(int x = 0; x < len; x++) {
        if(strcmp(laender[x], bundesland) == 0 && bewohner[x] >= anzahl) {
            char *zeile = (char *)malloc(100 * sizeof(char));  // Allocate space for each city's string
            sprintf(zeile, "Die Stadt %s hat %d Einwohner.", staedte[x], bewohner[x]);
            zeile_array[d] = zeile;
            d++;
        }
    }

    write_file(zeile_array, d);

    // Free individual strings
    for(int i = 0; i < d; i++) {
        free(zeile_array[i]);
    }

    return 0;  // Importantly, return an integer in the main function
}
