void loadTable(char ****table)
{
    *table = (char ***) malloc(sizeof(char**));

    if (!*table) {
        printf("Allocation error for table rows.\n");
        return;
    }

    // Use parentheses to ensure correct dereferencing
    (*table)[0] = (char**) malloc(COLUMNS * sizeof(char*));

    if (!(*table)[0]) {
        printf("Allocation error for table columns.\n");
        return;
    }

    // Allocate space for a string containing "a" followed by '\0'
    (*table)[0][0] = (char*) malloc(2 * sizeof(char));

    (*table)[0][0][0] = 'a'; // You can use 'a' directly, no need for (char)(97)
    (*table)[0][0][1] = '\0';
}
