fin = fopen("file1.txt", "r");

char* url = NULL;
if (fin) {
    char* line;
    while ((line = read_line(fin)) != NULL) {
        if ((url = strstr(line, "url=")) != NULL) {
            // Allocate memory for url copy
            url = strndup(url, strlen(url) - 4); // Adjust length to exclude "url=" prefix
            if (url == NULL) {
                fprintf(stderr, "Error: Memory allocation failed\n");
                exit(1); // Handle allocation failure
            }
            fprintf(stdout, "%s\n", url);
        }
        free(line);
    }
}

printf("line is: %s\n", url);

// Free the allocated memory for url
if (url) {
    free(url);
}

fclose(fin);
