char *homeDirectory = getenv("HOME");
if (homeDirectory) {
    char filePath[1024];
    snprintf(filePath, sizeof(filePath), "%s/Desktop/folder/file", homeDirectory);
    int fd = open(filePath, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        // Handle error...
    }
} else {
    fprintf(stderr, "HOME environment variable is not set\n");
    // Handle error...
}
