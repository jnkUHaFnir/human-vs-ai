    char *align_text(char *text)
    {
        const cols = 16;
        const rows = 8;
        int remain, nspaces;
        int j, base_len;
        char *fit_text;
    
        remain = strlen(text) % cols;
        base_len = strlen(text) - remain;
        nspaces = (cols - remain)/2;
    
        fit_text = malloc( strlen(text) + nspaces + 1 );
    
        if (base_len > 0)
            strncpy(fit_text, text, base_len);
    
        for (j = 0; j < nspaces; j++)
            fit_text[j + base_len] = ' ';
    
        strcat(&fit_text[base_len + nspaces], &text[base_len]);
    
        return fit_text;
    }