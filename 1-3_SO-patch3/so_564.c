    char *name = malloc(4);
    int inputAsingleChar,i=0;
    printf("Your name: \n");
    while((inputAsingleChar = getchar()) != '\n' && inputAsingleChar != EOF)
    {
        name[i++] = inputAsingleChar ;
        name = realloc(name, i+1);
    }
    name[i] = '\0';
    printf("Name: %s  \n", name);
    free(name);