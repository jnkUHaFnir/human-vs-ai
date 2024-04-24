fin = fopen("file1.txt", "r");
char* urlCopy = NULL;

if (fin) {
    char* line;
    while (line = read_line(fin)) {
        if ((url = strstr(line, "url=")) != NULL) {
            urlCopy = strdup(url);  // Make a copy of the data
            fprintf(stdout, "%s\n", url);
        }
        free(line);
    }
}

printf("line is: %s\n", urlCopy);  // Use the copied data
free(urlCopy);  // Free the copied data
fclose(fin);
