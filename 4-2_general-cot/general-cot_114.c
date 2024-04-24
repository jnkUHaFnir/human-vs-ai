#include <stdio.h>
#include <stdlib.h>

#define ROWS 1
#define COLUMNS 7

void loadTable(char ****table)
{
    *table = (char ***)malloc(ROWS * sizeof(char**)); // Allocate memory for rows

    if (!*table)
    {
        printf("Allocation error for table rows.");
        return;
    }

    (*table)[0] = (char**)malloc(COLUMNS * sizeof(char*)); // Allocate memory for columns in row 0

    if (!(*table)[0])
    {
        printf("Allocation error for table columns.");
        return;
    }

    (*table)[0][0] = (char*)malloc(2 * sizeof(char)); // Allocate memory for a cell

    (*table)[0][0][0] = 'a'; // Assign 'a' to the first element
    (*table)[0][0][1] = '\0'; // Null terminate the string
}

int main()
{
    char ***table;

    loadTable(&table);

    // Access and print the first element
    if (table)
    {
        printf("%c\n", table[0][0][0]);
    }

    return 0;
}
