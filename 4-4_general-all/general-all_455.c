#include <stdio.h>
#include <stdlib.h>

#define ROWS 1
#define COLUMNS 7

void loadTable(char ****table)
{
    *table = (char ***)malloc(ROWS * sizeof(char**));

    if (!*table) {
        printf("Allocation error for table rows.\n");
        return;
    }

    (*table)[0] = (char**)malloc(COLUMNS * sizeof(char*));

    if (!(*table)[0]) {
        printf("Allocation error for table columns.\n");
        return;
    }

    (*table)[0][0] = (char*)malloc(2 * sizeof(char));

    (*table)[0][0][0] = 'a';
    (*table)[0][0][1] = '\0';
}

int main()
{
    char ***table;

    loadTable(&table);

    printf("Value at first row, first column: %s\n", table[0][0]);

    // Freeing the allocated memory
    free(table[0][0]);
    free(table[0]);
    free(table);

    return 0;
}
