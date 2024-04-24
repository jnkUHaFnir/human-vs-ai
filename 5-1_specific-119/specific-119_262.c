void upis(struct futbaler* pok, int n)
{
    int i;
    char buffer[4]; // Buffer to read input for godiste

    for(i=0; i<n; i++)
    {
        printf("Ime igraca #%d: ", i+1);
        scanf("%s",(pok+i)->ime);
        printf("Prezime igraca #%d: ", i+1);
        scanf("%s",(pok+i)->prezime);
        printf("Pozicija igraca #%d: ", i+1);
        scanf("%s",(pok+i)->pozicija);
        
        // Read godiste using fgets to avoid buffer overflows
        printf("Godiste igraca #%d: ", i+1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character if present
        strcpy((pok+i)->godiste, buffer);
    }
}
