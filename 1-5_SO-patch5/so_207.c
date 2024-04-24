    int r = rand();
    char* str = (char*)malloc(sizeof(char)*20);
    sprintf(str, "%d", r);
    free(str);