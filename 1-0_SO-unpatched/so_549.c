    char* input = malloc(256);
    if(input == NULL){
        //uppon bad allocation NULL will be returned by malloc
	    perror("malloc");
        return EXIT_FAILURE;
    }
         