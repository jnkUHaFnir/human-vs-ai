char godiste[4];
char godiste[5];
scanf("%14s", (pok+i)->ime);
void upis(struct futbaler* pok, int n)
{
    int i;
    for(i=0; i<n;i++)
    {
        printf("Ime igraca #%d: ",i+1);
        scanf("%14s", (pok+i)->ime); // Limit input to prevent buffer overflow
        printf("Prezime igraca #%d: ",i+1);
        scanf("%19s", (pok+i)->prezime); // Adjusted according to the size of the array
        printf("Pozicija igraca #%d: ",i+1);
        scanf("%14s", (pok+i)->pozicija); // Adjusted according to the size of the array
        printf("Godiste igraca #%d: ",i+1);
        scanf("%4s", (pok+i)->godiste); // Limit input to prevent buffer overflow, considering godiste[5]
    }
}
