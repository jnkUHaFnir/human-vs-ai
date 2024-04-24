    srand(time(NULL));
    int r = rand();
    char* str = (char*)malloc(sizeof(char)*20);
    sprintf(str, "%06d", r);
    char* s = concat("foo-", str);
    printf("%s",s);
    free(str);
    free(s);
      
    return 0;