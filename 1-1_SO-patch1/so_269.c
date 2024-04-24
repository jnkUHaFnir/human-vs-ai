    // +1 for the terminating NULL pointer required for the 
    // second argument of execv
 
    char **list = malloc((argc + 1) * sizeof *list); 
    if(list == NULL) {
        printf("not enough memory to allocate\n");
        // handle it
    }
    int i = 0;
    for(i = 0; i < argc; ++i) { 
        list[i] = malloc(strlen(argv[i])+1);
        if(list[i] == NULL) {
            printf("not enough memory to allocate\n");
            // handle it
        }
        strcpy(list[i], argv[i]);
    }
    
    list[argc] = NULL;  // terminate the array with the NULL pointer
    execv(list[0], list);
 