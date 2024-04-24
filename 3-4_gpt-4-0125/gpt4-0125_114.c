#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 7

void loadTable(char ****table)
{
        *table = (char ***) malloc(sizeof(char**)); // Allocate memory for one pointer to pointer to char (row)

        if (!*table) {
            printf("Allocation error for table rows.\n");
            return;
        }

        // Here you need to correct the dereferencing and indexing precedence
        (*table)[0] = (char**) malloc(COLUMNS * sizeof(char*)); // Allocate memory for COLUMNS pointers to char (columns)

        if (!(*table)[0]) {
            printf("Allocation error for table columns.\n");
            return;
        }

        // Corrected dereferencing
        (*table)[0][0] = (char*) malloc(2 * sizeof(char)); // Allocate memory for a 2 char string (to hold 'a' and '\0')

        (*table)[0][0][0] = 'a'; // Assign 'a' to the first position
        (*table)[0][0][1] = '\0'; // Null-terminate the string
}

int main()
{
    char ***table;

    loadTable(&table);

    // Always good to test our result
    printf("First element: %s\n", table[0][0]);

    // Remember to free memory to prevent memory leaks
    free(table[0][0]); // Free the string
    free(table[0]); // Free the column pointers array
    free(table); // Free the row pointer

    return 0;
}
