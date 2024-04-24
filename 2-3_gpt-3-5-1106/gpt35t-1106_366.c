void extract(char *s1, char *s2) {
    char *p, *q;
    q = s2;
    for (p = s1; *p != '\0'; p++) {
        if (strncmp(p, "www.", 4) == 0) { // Check if the web address starts with www.
            char *end = strstr(p, ".edu");
            if (end != NULL) { // Check if the web address ends with .edu
                while (p < end) {
                    *q = *p;
                    q++;
                    p++;
                }
                *q = '\0';
                return;
            }
        }
    }
    strcpy(s2, "Web address starting with www. and ending with .edu not found");
}
