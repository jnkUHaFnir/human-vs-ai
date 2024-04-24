    // It is the callers responsibility to free the returned string.
    char *fixString(char *str) {
        int len;
        char *dest;
        len = strlen(str);
        dest = malloc(len + 2);
        dest[0] = '/';
        strcpy(dest + 1, str);
        return dest;
    }