char *deleteLastChar(char* s)
{
    int rozmiar, i;
    char *tab1;

    rozmiar = strlen(s);
    
    // Check if string is empty
    if (rozmiar == 0) {
        return NULL;
    }
    
    // Allocate memory for the new string
    tab1 = (char*)malloc(rozmiar * sizeof(char));
    if (tab1 == NULL) {
        return NULL;
    }
    
    // Copy all characters except the last one
    for(i = 0; i < rozmiar - 1; i++)
    {
        tab1[i] = s[i];
    }
    tab1[rozmiar - 1] = '\0'; // Add null terminator
    
    free(s); // Free the original string

    return tab1;
}
