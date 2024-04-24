    char *s = strdup("tata");
    if(!s){
       fprintf(stderr,"Error");
       exit(EXIT_FAILURE);
    }
    return s;