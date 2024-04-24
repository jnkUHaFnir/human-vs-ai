#define COLUMNS 7

void loadTable(char ****table) {
    *table = (char ***)malloc(sizeof(char**)); // Allocate memory for rows

    if (!*table) {
        printf("Allocation error for table rows.\n");
        return;
    }

    // Allocate memory for columns in the first row
    (*table)[0] = (char**)malloc(COLUMNS * sizeof(char*));

    if (!(*table)[0]) {
        printf("Allocation error for table columns.\n");
        return;
    }

    // Allocate memory for the first cell of the first column and set to 'a'
    (*table)[0][0] = (char*)malloc(2 * sizeof(char));
    if (!(*table)[0][0]) {
        printf("Allocation error for table cell.\n");
        return;
    }

    (*table)[0][0][0] = 'a'; // Use character literal directly
    (*table)[0][0][1] = '\0'; // null-terminate the string
}

int main() {
    char ***table;

    loadTable(&table);

    // Use the 2D array and also make sure to free the memory allocated

    // Example of usage (Don't forget to check if table is not NULL before using it)
    printf("%c\n", table[0][0][0]); // Will print 'a'

    // Free allocated memory
    free(table[0][0]); // Free the string containing 'a'
    free(table[0]);    // Free the first row of char* pointers
    free(table);       // Free the char** pointers

    return 0;
}
