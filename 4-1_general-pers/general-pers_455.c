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
        free(*table);  // Free previously allocated memory before returning
        *table = NULL;
        return;
    }

    (*table)[0][0] = (char*)malloc(2 * sizeof(char));

    if (!(*table)[0][0]) {
        printf("Allocation error for table content.");
        free((*table)[0]);  // Free columns memory
        free(*table);       // Free rows memory
        *table = NULL;
        return;
    }

    (*table)[0][0][0] = 'a';
    (*table)[0][0][1] = '\0';  // Null-terminate the string
}

int main()
{
    char ***table;

    loadTable(&table);

    // Access and print the value to test
    printf("%s\n", (*table)[0][0]);

    // Free memory
    free((*table)[0][0]);  // Free content memory
    free((*table)[0]);     // Free columns memory
    free(*table);          // Free rows memory
    free(table);           // Free pointer memory

    return 0;
}
