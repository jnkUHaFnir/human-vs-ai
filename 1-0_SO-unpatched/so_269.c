    // +1 for the terminating NULL pointer required for the 
    // second argument of execv
 
    char **list = malloc((argc + 1) * sizeof *list); 
    if(list == NULL) {
        printf("not enough memory to allocate\n");
        // handle it
    }
    int i = 0;
    for(i = 0; i < argc; ++i) {
        // strdup creates a pointer to a new string
        // which is a duplicate of the string argv[i]
        // this does effectively the same as the commented 
        // out block after the below statement.
        // include the header string.h for the prototype
        // of strdup POSIX function.
        list[i] = strdup(argv[i]);
        /* 
        list[i] = malloc(strlen(argv[i])+1);
        if(list[i] == NULL) {
            printf("not enough memory to allocate\n");
            // handle it
        }
        strcpy(list[i], argv[i]);
        */
    }
    
    list[argc] = NULL;  // terminate the array with the NULL pointer
    execv(list[0], list);
 