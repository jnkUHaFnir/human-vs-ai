#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 7

void loadTable(char ****table)
{
    *table = (char ***)malloc(sizeof(char **));

    if (!*table)
    {
        printf("Allocation error for table rows.\n");
        return;
    }

    (*table)[0] = (char **)malloc(COLUMNS * sizeof(char *));

    if (!(*table)[0])
    {
        printf("Allocation error for table columns.\n");
        return;
    }

    (*table)[0][0] = (char *)malloc(2 * sizeof(char));

    if (!(*table)[0][0])
    {
        printf("Allocation error for string.\n");
        return;
    }

    (*table)[0][0][0] = 'a'; // Directly assigning character 'a'
    (*table)[0][0][1] = '\0'; // Null-terminator for string
}

int main()
{

    char ***table;

    loadTable(&table);

    printf("%c\n", table[0][0][0]); // To test if 'a' is correctly placed

    // Free the allocated memory to prevent memory leaks.
    free(table[0][0]); // Free the string
    free(table[0]); // Free the array of char* pointers
    free(table); // Free the array of char** pointers

    return 0;
}
