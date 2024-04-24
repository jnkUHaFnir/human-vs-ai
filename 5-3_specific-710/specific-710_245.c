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
            // Handle realloc error
            free(s);
            exit(1);
        }
        s = temp;
    }

    printf("Geben Sie Bitte die Name:\n");
    fgets(s[scount].name, sizeof(s[scount].name), stdin);

    while (s[scount].name[index] != '\n')
    {
        index++;
    }
    s[scount].name[index] = '\0';
    scount++;
}
