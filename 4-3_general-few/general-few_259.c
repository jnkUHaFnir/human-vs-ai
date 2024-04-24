void upis(struct futbaler* pok, int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        printf("Ime igraca #%d: ", i+1);
        scanf("%14s", (pok+i)->ime); // Limit input to 14 characters
        printf("Prezime igraca #%d: ", i+1);
        scanf("%19s", (pok+i)->prezime); // Limit input to 19 characters
        printf("Pozicija igraca #%d: ", i+1);
        scanf("%14s", (pok+i)->pozicija); // Limit input to 14 characters
        printf("Godiste igraca #%d: ", i+1);
        scanf("%4s", (pok+i)->godiste); // Limit input to 4 characters
    }
}
