#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 7

void loadTable(char ****table) {
    // Allocate memory for a single row of char**
    *table = (char ***)malloc(sizeof(char**));
    if (!*table) {
        printf("Allocation error for table rows.\n");
        return;
    }

    // Allocate memory for an array of char* within the first row
    (*table)[0] = (char**)malloc(COLUMNS * sizeof(char*));
    if (!(*table)[0]) {
        printf("Allocation error for table columns.\n");
        return;
    }

    // Allocate memory for the first string in the first column
    (*table)[0][0] = (char*)malloc(2 * sizeof(char));
    if (!(*table)[0][0]) {
        printf("Allocation error for string.\n");
        return;
    }

    // Assign the character 'a' followed by a null terminator to the first string
    (*table)[0][0][0] = 'a'; // char literals are already of type char, no need to cast
    (*table)[0][0][1] = '\0';
}

int main() {
    char ***table;

    loadTable(&table);

    // Do remember to free the memory after you're done using it to avoid memory leak
    // For example:
    free(table[0][0]);
    free(table[0]);
    free(table);

    return 0;
}
