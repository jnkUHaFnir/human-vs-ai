void extract(char *s1, char *s2) {
    char *p, *q;
    q = s2;
    int found = 0;

    for (p = s1; *p != '\0'; p++) {
        if (strncmp(p, "www.", 4) == 0) {
            found = 1;
            *q++ = *p++;
            *q++ = *p++;
            *q++ = *p++;
            *q++ = *p;

            while (*p != '/' && *p != '\0') {
                *q++ = *p++;
            }
            *q = '\0';
            break;
        }
    }

    if (!found) {
        strcpy(s2, "Web address starting with www. and ending with .edu not found");
    }
}
