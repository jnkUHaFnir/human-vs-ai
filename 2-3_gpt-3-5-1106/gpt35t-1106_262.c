void upis(struct futbaler* pok, int n)
{
    int i;

    for(i=0; i<n;i++)
    {
        printf("Ime igraca #%d: ",i+1);
        scanf(" %[^\n]",(pok+i)->ime);  // add a space before %[^\n]
        printf("Prezime igraca #%d: ",i+1);
        scanf(" %[^\n]",(pok+i)->prezime);
        printf("Pozicija igraca #%d: ",i+1);
        scanf(" %[^\n]",(pok+i)->pozicija);
        printf("Godiste igraca #%d: ",i+1);
        scanf(" %[^\n]",(pok+i)->godiste);
    }
}
