    srand(time(NULL));
    int r = rand();
    char* str = (char*)malloc(sizeof(char)*20);
    snprintf(str, 7, "%d", r);
    
    if (strlen(str) < 6) {  /* if r had less than 6 digits */
        sprintf(str, "%06d", r);
    }
    char* s = concat("foo-", str);
    printf("%s",s);
    free(str);
    free(s);
      
    return 0;