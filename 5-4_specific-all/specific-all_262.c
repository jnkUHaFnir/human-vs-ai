void upis(struct futbaler* pok, int n) {
    int i;
    char buffer[256]; // Buffer to read the input

    for (i = 0; i < n; i++) {
        printf("Ime igraca #%d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%14[^\n]", (pok + i)->ime);

        printf("Prezime igraca #%d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%19[^\n]", (pok + i)->prezime);

        printf("Pozicija igraca #%d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%14[^\n]", (pok + i)->pozicija);

        printf("Godiste igraca #%d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%3[^\n]", (pok + i)->godiste);
    }
}
