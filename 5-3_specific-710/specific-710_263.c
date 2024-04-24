void upis(struct futbaler* pok, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("Ime igraca #%d: ", i + 1);
        fgets((pok + i)->ime, sizeof((pok + i)->ime), stdin);
        (pok + i)->ime[strcspn((pok + i)->ime, "\n")] = '\0'; // Remove newline
        printf("Prezime igraca #%d: ", i + 1);
        fgets((pok + i)->prezime, sizeof((pok + i)->prezime), stdin);
        (pok + i)->prezime[strcspn((pok + i)->prezime, "\n")] = '\0'; // Remove newline
        printf("Pozicija igraca #%d: ", i + 1);
        fgets((pok + i)->pozicija, sizeof((pok + i)->pozicija), stdin);
        (pok + i)->pozicija[strcspn((pok + i)->pozicija, "\n")] = '\0'; // Remove newline
        printf("Godiste igraca #%d: ", i + 1);
        fgets((pok + i)->godiste, sizeof((pok + i)->godiste), stdin);
        (pok + i)->godiste[strcspn((pok + i)->godiste, "\n")] = '\0'; // Remove newline
    }
}
