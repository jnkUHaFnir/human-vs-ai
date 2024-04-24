    // string to lower
    char *str2lower (char *str)
    {
        if (!str) return NULL;
    
        char *p = str;
    
        for (; *p; p++)
            if (isupper((unsigned char)*p))
                *p ^= ('A' ^ 'a');
    
        return str;
    }
    
    // Returns true if word is in dictionary else false
    bool check(const char *word)
    {
        char lcword[LENGTH+1];          /* make a copy of word from txt to convert to lc */
        size_t len = strlen (word);     /* get length of word */
        unsigned h;
        
        if (len > LENGTH) { /* validate word will fit */
            fprintf (stderr, "error: check() '%s' exceeds LENGTH.\n", word);
            return false;
        }
        memcpy (lcword, word, len+1);   /* copy word to lower-case word */
        
        h = hash (str2lower(lcword));   /* convert to lower-case then hash */
        for (node *n = table[h]; n; n = n->next)    /* now loop over list nodes */
            if (strcmp (lcword, n->word) == 0)      /* compare lower-case words */
                return true;
            
        return false;
    }