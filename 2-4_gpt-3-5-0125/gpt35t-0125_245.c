void addNewStudent()
{
    int index = 0;
    if (scount == 0)
    {
        s = malloc(sizeof(students));
    }
    else
    {
        students *temp = realloc(s, sizeof(students) * scount);
        if (temp == NULL) {
            free(s); // Free the old memory if realloc fails
            printf("Memory reallocation failed. Exiting program.\n");
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
