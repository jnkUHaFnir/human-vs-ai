#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 7

void loadTable(char ****table)
{
    *table = (char ***)malloc(sizeof(char**));

    if (!*table) {
        printf("Allocation error for table rows.");
        return;
    }

    (*table)[0] = (char**)malloc(COLUMNS * sizeof(char*));

    if (!(*table)[0]) {
        printf("Allocation error for table columns.");
        return;
    }

    (*table)[0][0] = (char*)malloc(2 * sizeof(char));

    (*table)[0][0][0] = (char)(97);
    (*table)[0][0][1] = '\0';
}

int main()
{
    char ***table;

    loadTable(&table);

    // Access the value
    printf("%c\n", (*table)[0][0][0]);

    // Free the memory
    free((*table)[0][0]);
    free((*table)[0]);
    free(*table);
    free(table);

    return 0;
}
