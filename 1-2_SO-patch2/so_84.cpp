    static strip_copy(char const *s, char *buf, const char * SPACE)
    {
        if (buf)
        {
            char *p = buf;
            char const *q;
            int n;
            for (q = s; *q; q += n + strspn(q+n, SPACE))
            {
                n = strcspn(q, SPACE);
                strncpy(p, q, n);
                p += n;
            }
            *p++ = '\0';
            buf = (char*)realloc(buf, p - buf);
        }
    }
    
    // Then call it like this
    char *buf = new[1 + strlen(s)];
    strip_copy(s, buf, ' ');
    // use buf
    delete [] buf;