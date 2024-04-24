    char *password = NULL;
    int pwmax = 0;
    int pwlen = 0;
    while (1) {
        int chr = fgetc(stdin);
        if (chr == EOF)
            break;
        if (chr == '\n')
            break;
        if (pwlen >= pwmax) {
            pwmax += 100;
            password = realloc(password,pwmax);
            if (password == NULL)
                exit(1);
        }
        password[pwlen++] = chr;
    }
    password = realloc(password,pwlen + 1);
    if (password == NULL)
        exit(1);
    password[pwlen] = 0;