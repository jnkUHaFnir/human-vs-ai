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

    char *zeile_array[MAX_LAENGE_ARR];
    int d = 0;
    for (int x = 0; x < len; x++) {
        if (strcmp(laender[x], bundesland) == 0 && bewohner[x] >= anzahl) {
            char *zeile = (char*)malloc(100); // allocating memory for each zeile
            if(zeile == NULL){
                fprintf(stderr, "Memory allocation failed. Exiting...\n");
                exit(1);
            }
            snprintf(zeile, 100, "Die Stadt %s hat %d Einwohner.", staedte[x], bewohner[x]);
            zeile_array[d] = zeile; // putting it into array
            d++;
        }
    }
    write_file(zeile_array, d);
    
    // Free allocated memory
    for (int i = 0; i < d; i++) {
        free(zeile_array[i]);
    }

    return 0;
}
