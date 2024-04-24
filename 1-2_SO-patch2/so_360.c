    char buf[255] = "foo baa CODE =     12345-MODE-12453-CODE-12355";
    char *val = getcode(buf); //12345
    //... 
    free(val);