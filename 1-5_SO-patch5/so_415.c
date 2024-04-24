    const char *filename = /*something*/;
    size_t len = strlen(filename);
    char *newfilename = malloc(len+1); /* or let your caller provide a buffer*/
    if (!newfilename) /* handle error */;
    strcpy(newfilename, filename);
    newfilename[len - 3] = 0;