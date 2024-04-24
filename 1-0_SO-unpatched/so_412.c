    int file_exists(char *filename)
    {
        struct stat buffer;
        char fullpath[50], *path;
        path = "/home/Nips/"
        if ((strlen(path) + strlen(filename)) >= 50) {
            printf("filename too long!\n");
            return 0;
        }
        strcpy(fullpath, path);
        strcat(fullpath, filename);
        if (stat(fullpath, &buffer) == 0) {
            return 1;
        }
        path = "/etc/";
        strcpy(fullpath, path);
        strcat(fullpath, filename);
        if (stat(fullpath, &buffer) == 0) {
            return 1;
        }
        printf("File not found!\n");
        return 0;
    }