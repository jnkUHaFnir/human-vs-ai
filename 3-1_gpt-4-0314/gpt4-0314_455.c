#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 7

void loadTable(char ****table)
{
        *table = (char ***) malloc(sizeof(char**));

        if (!*table) {
            printf("Allocation error for table rows.");
            return;
        }

        (*table)[0] = (char**) malloc(COLUMNS * sizeof(char*)); // Change here

        if (!(*table)[0]) { // Change here
            printf("Allocation error for table columns.");
            return;
        }

        (*table)[0][0] = (char*) malloc(2 * sizeof(char)); // Change here

    (*table)[0][0][0] = (char)(97);
    (*table)[0][0][1] = '\0';
}

int main()
{

    char ***table;

    loadTable(&table);

    printf("%c\n", table[0][0][0]); // Print the value to check

    // Free memory (this should ideally be done in a separate function)
    free(table[0][0]);
    free(table[0]);
    free(table);

    return 0;
}
