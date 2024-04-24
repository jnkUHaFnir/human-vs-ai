void upis(struct futbaler* pok, int n)
{
    int i;
    char temp[256]; // Temporary buffer to consume newline character

    for(i = 0; i < n; i++)
    {
        printf("Ime igraca #%d: ", i + 1);
        scanf("%s", (pok + i)->ime);

        printf("Prezime igraca #%d: ", i + 1);
        scanf("%s", (pok + i)->prezime);

        printf("Pozicija igraca #%d: ", i + 1);
        scanf("%s", (pok + i)->pozicija);

        // Consume newline character left in the buffer
        fgets(temp, sizeof(temp), stdin);

        printf("Godiste igraca #%d: ", i + 1);
        scanf("%s", (pok + i)->godiste);

        // Consume newline character left in the buffer
        fgets(temp, sizeof(temp), stdin);
    }
}
