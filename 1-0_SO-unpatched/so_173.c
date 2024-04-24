    char* home = getenv("HOME");
    if (home == NULL) goto error;
    char* path = "/Desktop/folder/file"
    size_t len = strlen(home) + strlen(path) + 1;
    char* fullpath = malloc(len);
    strncpy(fullpath, len, home);
    strncat(fullpath, len, path);
    int fd = open(fullpath, O_RDONLY);
    free(fullpath);