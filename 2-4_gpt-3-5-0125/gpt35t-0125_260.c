void upis(struct futbaler* pok, int n)
{
    int i;

    for(i=0; i<n;i++)
    {
        printf("Ime igraca #%d: ",i+1);
        scanf("%s",(pok+i)->ime);
        printf("Prezime igraca #%d: ",i+1);
        scanf("%s",(pok+i)->prezime);
        printf("Pozicija igraca #%d: ",i+1);
        scanf("%s",(pok+i)->pozicija);
        printf("Godiste igraca #%d: ",i+1);
        scanf("%d",&((pok+i)->godiste));
    }
}
