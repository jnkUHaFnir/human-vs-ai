#include <stdio.h>
#include <stdlib.h>

#define ROWS 1
#define COLUMNS 7

void loadTable(char ****table)
{
    *table = (char ***)malloc(ROWS * sizeof(char**));

    if (!*table) {
        printf("Allocation error for table rows.");
        return;
    }

    (*table)[0] = (char **)malloc(COLUMNS * sizeof(char*));

    if (!(*table)[0]) {
        printf("Allocation error for table columns.");
        return;
    }

    (*table)[0][0] = (char *)malloc(2 * sizeof(char));

    **(*table)[0] = 'a';
    *(*(*table))[1] = '\0';
}

int main()
{
    char ***table;

    loadTable(&table);

    // Access and print the value at table[0][0]
    printf("Value at table[0][0]: %s\n", table[0][0]);

    // Free allocated memory
    free(table[0][0]);
    free(table[0]);
    free(table);

    return 0;
}
