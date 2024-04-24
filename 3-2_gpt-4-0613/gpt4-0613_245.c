void addNewStudent()
{
    int index = 0;
    scount++; 

    if (scount == 1)
    {
        s = (students*)malloc(sizeof(students));
    }
    else
    {
        students *tmp = realloc(s, sizeof(students) * scount);
        if (tmp == NULL)
        {
            printf("Error reallocating memory!\n");
            return;
        }
        else
        {
            s = tmp;
        }
    }

    printf("Geben Sie Bitte die Name:\n");
    // ensure that previous newline is consumed before reading name
    while (getchar() != '\n');
    fgets(s[scount - 1].name, sizeof(s[scount - 1].name), stdin);

    while (s[scount - 1].name[index] != '\n')
    {
        index++;
    }
    s[scount - 1].name[index] = '\0';
}
