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
        free(*table);
        return;
    }

    (*table)[0][0] = (char*)malloc(2 * sizeof(char));

    if (!(*table)[0][0]) {
        printf("Allocation error for table elements.");
        free((*table)[0]);
        free(*table);
        return;
    }

    (*table)[0][0][0] = 'a';
    (*table)[0][0][1] = '\0';
}

int main()
{
    char ***table;

    loadTable(&table);

    printf("Table contents: %s\n", table[0][0]);

    // Free allocated memory
    free(table[0][0]);
    free(table[0]);
    free(table);

    return 0;
}
