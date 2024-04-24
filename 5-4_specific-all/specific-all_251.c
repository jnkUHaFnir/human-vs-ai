#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input3.h"

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

    char *zeile_array[MAX_LAENGE_ARR]; // Modify the allocation method here
    int d = 0;

    for (int x = 0; x < len; x++) {
        if (strcmp(laender[x], bundesland) == 0 && bewohner[x] >= anzahl) {
            // Allocate memory for each zeile separately
            char *zeile = (char*)malloc(100 * sizeof(char));
            if (zeile == NULL) {
                perror("Memory allocation failed");
                exit(1);
            }
            sprintf(zeile, "Die Stadt %s hat %d Einwohner.", staedte[x], bewohner[x]);
            zeile_array[d] = zeile;
            d++;
        }
    }

    write_file(zeile_array, d);

    // Free memory allocated for each zeile
    for (int i = 0; i < d; i++) {
        free(zeile_array[i]);
    }

    return 0;
}
