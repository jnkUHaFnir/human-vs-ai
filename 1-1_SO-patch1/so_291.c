    char line[80], name[80];
    char toomuch;
    if (fgets(line, sizeof line, stdin) != NULL && sscanf(line, " %80[0-9A-Za-z] %c", name, &toomuch) == 1) {
        printf("name=(%s)\n", name);
    }