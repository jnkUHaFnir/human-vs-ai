#include <stdio.h>
#include <stdlib.h>

#define ROWS 1
#define COLUMNS 7

void loadTable(char ****table) {
    *table = (char ***)malloc(ROWS * sizeof(char**)); // Allocate memory for rows

    if (!*table) {
        printf("Allocation error for table rows.");
        return;
    }

    (*table)[0] = (char**)malloc(COLUMNS * sizeof(char*)); // Allocate memory for columns

    if (!(*table)[0]) {
        printf("Allocation error for table columns.");
        return;
    }

    (*table)[0][0] = (char*)malloc(2 * sizeof(char)); // Allocate memory for the cell

    (*table)[0][0][0] = 'a'; // Assign value 'a' to the cell
    (*table)[0][0][1] = '\0'; // Null terminate the string
}

int main() {
    char ***table;

    loadTable(&table);

    // Output the value in the first row, first column
    printf("Value: %s\n", table[0][0]);

    // Free the allocated memory
    free(table[0][0]);
    free(table[0]);
    free(table);

    return 0;
}
