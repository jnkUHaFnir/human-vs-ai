#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare MAX_LAENGE_ARR and MAX_LAENGE_STR here

void free_memory(char *zeile_array[], int len) {
    for (int i = 0; i < len; i++) {
        free(zeile_array[i]);
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Aufruf: %s <anzahl> <bundesland>\n", argv[0]);
        printf("Beispiel: %s 100 Bayern\n", argv[0]);
        printf("Klein-/Großschreibung beachten!\n");
        exit(1);
    }

    int anzahl = atoi(argv[1]);
    char *bundesland = argv[2];

    char staedte[MAX_LAENGE_ARR][MAX_LAENGE_STR];
    char laender[MAX_LAENGE_ARR][MAX_LAENGE_STR];
    int bewohner[MAX_LAENGE_ARR];

    int len = read_file("staedte.csv", staedte, laender, bewohner);

    char *zeile_array[MAX_LAENGE_ARR];

    for (int x = 0; x < len; x++) {
        if (strcmp(laender[x], bundesland) == 0 && bewohner[x] >= anzahl) {
            char *zeile = (char *) malloc(100); // allocate memory for each string
            sprintf(zeile, "Die Stadt %s hat %d Einwohner.", staedte[x], bewohner[x]);
            zeile_array[d] = zeile;
            d++;
        }
    }

    write_file(zeile_array, d);

    // Free allocated memory
    free_memory(zeile_array, d);

    return 0;
}
