    char password[1000];
    fgets(password,sizeof(password),stdin);
    char *cp = strchr(password,'\n');
    if (cp != NULL)
        *cp = 0;