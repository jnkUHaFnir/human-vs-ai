    char **argList = NULL;
    unsigned int numArgs = 0;
    while (temp != NULL) {
        numArgs++;
        
        /* Reallocate space for your argument list */
        argList = realloc(argList, numArgs * sizeof(*argList));
        /* Copy the current argument */
        argList[numArgs - 1] = malloc(strlen(temp) + 1, 1); /* The +1 for length is for the terminating '\0' character */
        snprintf(argList[numArgs - 1], strlen(temp) + 1, "%s", temp);
        printf("%s\n", temp);
        temp = strtok(NULL, " ");
    }
    /* Store the last NULL pointer */
    numArgs++;
    argList = realloc(argList, numArgs * sizeof(*argList));
    argList[numArgs - 1] = NULL;
    /* Finally, pass this to execvp */
    if(-1 == execvp(argList[0], argList))
    {
        /* Error */
    }