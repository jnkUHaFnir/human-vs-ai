void extract(const char *s1, char *s2) {
    const char *p = strstr(s1, "www.");
    if (p != NULL) {
        const char *q = strstr(p, ".edu");
        if (q != NULL) {
            int len = q - p + 4; // including ".edu"
            strncpy(s2, p, len);
            s2[len] = '\0';
        } else {
            strcpy(s2, "Web address starting with www. and ending with .edu not found");
        }
    } else {
        strcpy(s2, "Web address starting with www. not found");
    }
}
``` 

With this modification, the original input string `instr` remains unchanged, and the extracted web address or error message is stored in the `outstr` array correctly. This way, the program should work as expected.
