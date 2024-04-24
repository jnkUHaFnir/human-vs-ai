#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 7

void loadTable(char ****table) {
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

    *(*table)[0][0] = 'a'; // Assigning directly works too
    *(*table)[0][0 + 1] = '\0'; // You can also write it like this

    // Alternatively, you can use strcpy to set the value
    // strcpy((*table)[0][0], "a");
}

int main() {
    char ***table;

    loadTable(&table);

    printf("Value in table[0][0]: %s\n", table[0][0]);

    return 0;
}
