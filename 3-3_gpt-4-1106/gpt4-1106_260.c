struct futbaler {
    char ime[15];
    char prezime[20];
    char pozicija[15];
    char godiste[5];
};
scanf("%14s", (pok + i)->ime);
scanf("%19s", (pok + i)->prezime);
scanf("%14s", (pok + i)->pozicija);
scanf("%4s", (pok + i)->godiste);  // Note that we can now fit four characters plus the null terminator
void upis(struct futbaler* pok, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("Ime igraca #%d: ", i + 1);
        scanf("%14s", (pok + i)->ime);
        printf("Prezime igraca #%d: ", i + 1);
        scanf("%19s", (pok + i)->prezime);
        printf("Pozicija igraca #%d: ", i + 1);
        scanf("%14s", (pok + i)->pozicija);
        printf("Godiste igraca #%d: ", i + 1);
        scanf("%4s", (pok + i)->godiste);  // Allows for input "YYYY\0"
    }
}
