    char *line = fgets(currentWord[countX], 20, stdin);
    if (n) {
        int len = strlen(line);
        if (line[len-1] == '\n') {
            line[len-1] = 0;
        }
    }