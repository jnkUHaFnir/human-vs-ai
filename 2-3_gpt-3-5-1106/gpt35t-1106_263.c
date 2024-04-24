void upis(struct futbaler* pok, int n)
{
    int i;

    for(i=0; i<n;i++)
    {
        printf("Ime igraca #%d: ",i+1);
        fgets((pok+i)->ime, 15, stdin);
        printf("Prezime igraca #%d: ",i+1);
        fgets((pok+i)->prezime, 20, stdin);
        printf("Pozicija igraca #%d: ",i+1);
        fgets((pok+i)->pozicija, 15, stdin);
        printf("Godiste igraca #%d: ",i+1);
        fgets((pok+i)->godiste, 4, stdin);
    }
}
