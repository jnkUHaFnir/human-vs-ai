#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 7

void loadTable(char ****table)
{
    *table = (char ***)malloc(sizeof(char**));

    if (*table == NULL)
    {
        printf("Allocation error for table rows.");
        return;
    }

    (*table)[0] = (char **)malloc(COLUMNS * sizeof(char *));

    if ((*table)[0] == NULL)
    {
        printf("Allocation error for table columns.");
        free(*table); // Free previously allocated memory before returning
        return;
    }

    (*table)[0][0] = (char *)malloc(2 * sizeof(char));

    (*table)[0][0][0] = 'a';
    (*table)[0][0][1] = '\0';
}

int main()
{
    char ***table;

    loadTable(&table);

    // Access and print the value to verify
    printf("Value at [0][0]: %s\n", table[0][0]);

    // Don't forget to free the allocated memory
    free(table[0][0]);
    free(table[0]);
    free(table);

    return 0;
}
