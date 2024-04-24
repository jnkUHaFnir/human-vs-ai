    char * ptr = malloc(256);
    if(!ptr){
        return 1;
    }
    char * tmp = realloc(ptr, 512);
    if(!tmp){
        printf("Houston, we have a problem");
        // ptr is fine
    }