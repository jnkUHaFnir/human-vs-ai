#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LAENGE_STR 255
#define MAX_LAENGE_ARR 100

int read_file(char *dateiname, char staedte[][MAX_LAENGE_STR], char laender[][MAX_LAENGE_STR], int bewohner[]);
void write_file(char *result[], int len);

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
            char *zeile = (char*)malloc(100);
            sprintf(zeile, "Die Stadt %s hat %d Einwohner.", staedte[x], bewohner[x]);
            zeile_array[d] = zeile;
            d++;
        }
    }

    write_file(zeile_array, d);

    for (int i = 0; i < d; i++) {
        free(zeile_array[i]);
    }

    return 0;
}

int read_file(char *dateiname, char staedte[][MAX_LAENGE_STR], char laender[][MAX_LAENGE_STR], int bewohner[]) {
    FILE *fp = fopen(dateiname, "r");
    if (fp == NULL){
        perror(dateiname);
        exit(1);
    }

    char stadt[MAX_LAENGE_STR];
    char land[MAX_LAENGE_STR];
    int anzahl;
    int i = 0;
    int len;

    while (fscanf(fp, "\"%[^\"]\";\"%[^\"]\";%d\n", stadt, land, &anzahl) != EOF) {
        if (i >= MAX_LAENGE_ARR) {
            printf("ERROR: Die Datei ist größer als erwartet!\n");
            break;
        }

        len = strlen(land);
        strncpy(laender[i], land, len);
        laender[i][len] = '\0';

        len = strlen(stadt);
        strncpy(staedte[i], stadt, len);
        staedte[i][len] = '\0';

        bewohner[i] = anzahl;
        i++;
    }

    fclose(fp);
    return i;
}

void write_file(char *result[], int len) {
    FILE *fp = fopen("resultat.txt", "w");
    if (fp == NULL){
        perror("resultat.txt");
        exit(1);
    }

    for (int i = 0; i < len; i++) {
        fprintf(fp, "%s\n", result[i]);
    }

    fclose(fp);
}
