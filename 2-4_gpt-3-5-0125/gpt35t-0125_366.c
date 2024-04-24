void extract(char *s1, char *s2) {
    char *p = s1;
    char *q = s2;

    while (*p != '\0') {
        if (strncmp(p, "www.", 4) == 0) {
            p += 4;
            while (*p != '.' && *p != '\0') {
                *q++ = *p++;
            }
            if (*p == '.') {
                *q = *p;
                q++;
            } else {
                break;
            }
            while (*p != '\0') {
                *q++ = *p++;
            }
            *q = '\0';
            break;
        }
        p++;
    }
}
