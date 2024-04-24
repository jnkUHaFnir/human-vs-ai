    char * ptr = malloc(256);
    if(!ptr){
        return 1;
    }
    char * tmpPTR = realloc(ptr, 512);
    if(!tmpPTR){
        printf("Houston, we have a problem");
        // ptr is fine
    }else{
        ptr = tmpPTR;
    }
    // ptr is realloc()ed