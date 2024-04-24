void upis(struct futbaler* pok, int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        printf("Ime igraca #%d: ", i+1);
        scanf("%14s", (pok+i)->ime);  // Limiting input to 14 characters for 'ime'
        printf("Prezime igraca #%d: ", i+1);
        scanf("%19s", (pok+i)->prezime); // Limiting input to 19 characters for 'prezime'
        printf("Pozicija igraca #%d: ", i+1);
        scanf("%14s", (pok+i)->pozicija); // Limiting input to 14 characters for 'pozicija'
        printf("Godiste igraca #%d: ", i+1);
        scanf("%3s", (pok+i)->godiste);  // Limiting input to 3 characters for 'godiste'
    }
}
