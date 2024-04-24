    char* result = malloc(strlen(s1) + strlen(s2) + 1);
    assert(result);
    strcat(strcpy(result, s1), s2);