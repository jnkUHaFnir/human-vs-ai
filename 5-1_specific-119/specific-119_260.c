void upis(struct futbaler* pok, int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        printf("Ime igraca #%d: ", i+1);
        fgets((pok+i)->ime, sizeof((pok+i)->ime), stdin);
        printf("Prezime igraca #%d: ", i+1);
        fgets((pok+i)->prezime, sizeof((pok+i)->prezime), stdin);
        printf("Pozicija igraca #%d: ", i+1);
        fgets((pok+i)->pozicija, sizeof((pok+i)->pozicija), stdin);
        printf("Godiste igraca #%d: ", i+1);
        fgets((pok+i)->godiste, sizeof((pok+i)->godiste), stdin);
    }
}
(pok+i)->ime[strcspn((pok+i)->ime, "\n")] = '\0';
