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
        return;
    }

    (*table)[0][0] = (char*)malloc(2 * sizeof(char));

    (*table)[0][0][0] = 'a';
    (*table)[0][0][1] = '\0';
}

int main()
{

    char ***table;

    loadTable(&table);

    return 0;
}
