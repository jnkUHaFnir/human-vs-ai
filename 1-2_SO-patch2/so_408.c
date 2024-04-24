    char *xlat = charLookup[j];
    char clean_char = xlat[0];
    char *dirty_utf8 = xlat + 1;
    int dirty_len = strlen(dirty_utf8);
    if (strncmp(pCharInput,dirty_utf8,dirty_len) == 0) {
        *pCharOutput++ = clean_char;
        pCharInput += dirty_len
    }
    else {
        *pCharOutput++ = *pCharInput++;
    }