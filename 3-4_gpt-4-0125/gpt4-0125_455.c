void loadTable(char ****table) {
    *table = malloc(sizeof(char**));  // Allocate memory for the rows

    if (!*table) {
        printf("Allocation error for table rows.\n");
        return;
    }

    (*table)[0] = malloc(COLUMNS * sizeof(char*));  // Allocate memory for the columns in the first row

    if (!(*table)[0]) {
        printf("Allocation error for table columns.\n");
        return;
    }

    (*table)[0][0] = malloc(2 * sizeof(char));  // Allocate memory for the first column in the first row to hold a string of 1 character + null terminator

    if (!(*table)[0][0]) {
        printf("Allocation error for string.\n");
        return;
    }

    (*table)[0][0][0] = 'a';  // Assign the character 'a' to the first element
    (*table)[0][0][1] = '\0';  // Null-terminate the string
}
