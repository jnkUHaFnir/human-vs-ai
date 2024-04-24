    const char*p = "data";
    char *s = malloc(strlen(p)+1);
    if(!s){
       perror("malloc");
       exit(EXIT_FAILURE);
    }
    memcpy(s,p,strlen(p)+1);
    return s;