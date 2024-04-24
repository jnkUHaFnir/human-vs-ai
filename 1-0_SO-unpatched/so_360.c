    char buf[255] = "foo baa CODE =     12345-MODE-12453-CODE-12355";
    char *code = getcode(buf,256);
    
    if(code != NULL) {
    	printf("code = %s\n", code);
    	free(code);
    } else {
    	printf("Not found code.\n");
    }