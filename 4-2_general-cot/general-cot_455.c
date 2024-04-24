#include <stdio.h>
#include <stdlib.h>

#define ROWS 1
#define COLUMNS 7

void loadTable(char ****table) {
    *table = (char ***)malloc(ROWS * sizeof(char**));
    if (!*table) {
        printf("Allocation error for table rows.");
        return;
    }

    (*table)[0] = (char**)malloc(COLUMNS * sizeof(char*));
    if (!(*table)[0]) {
        printf("Allocation error for table columns.");
        free(*table); // Clean up previous allocation
        *table = NULL;
        return;
    }

    (*table)[0][0] = (char*)malloc(2 * sizeof(char));
    if (!(*table)[0][0]) {
        printf("Allocation error for table cell.");
        free((*table)[0]); // Clean up previous allocation
        free(*table);
        *table = NULL;
        return;
    }

    (*table)[0][0][0] = 'a';
    (*table)[0][0][1] = '\0';
}

int main() {
    char ***table = NULL;

    loadTable(&table);

    if (table) {
        printf("Cell [0][0]: %s\n", table[0][0]);
    }

    // Free allocated memory
    if (table) {
        free(table[0][0]);
        free(table[0]);
        free(table);
    }

    return 0;
}
