    char *remove_three(const char *filename) {
        size_t len = strlen(filename);
        char *newfilename = malloc(len-2);
        if (!newfilename) /* handle error */;
        memcpy(newfilename, filename, len-3);
        newfilename[len - 3] = 0;
        return newfilename;
    }