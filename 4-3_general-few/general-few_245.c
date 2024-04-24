s = (students*)realloc(s, sizeof(students) * (scount + 1));
void addNewStudent()
{
    int index = 0;
    if (scount == 0)
    {
        s = (students*)malloc(sizeof(students));
    }
    else
    {
        s = (students*)realloc(s, sizeof(students) * (scount + 1));
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
