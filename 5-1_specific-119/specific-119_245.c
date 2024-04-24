void addNewStudent()
{
    int index = 0;
    if (scount == 0)
    {
        s = (students*)malloc(sizeof(students));
    }
    else
    {
        students* temp = (students*)realloc(s, sizeof(students) * (scount + 1));
        if (temp == NULL) {
            printf("Memory reallocation failed\n");
            return;
        }
        s = temp;
    }

    printf("Geben Sie Bitte die Name:\n");
    fgets(s[scount].name, sizeof(s[scount].name), stdin);

    // Remove newline character if present
    char* newline = strchr(s[scount].name, '\n');
    if (newline != NULL) {
        *newline = '\0';
    }

    scount++;
}
