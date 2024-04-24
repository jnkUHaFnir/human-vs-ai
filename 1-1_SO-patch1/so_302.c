    void load(char ***array, int *index) { // Use pointer to pointer to pointer
        int riadok;
    	size_t len = 0;
    	char *buffer = NULL;
    	
    	printf("Slova:\n");
    	while( ( riadok = getline(&buffer,&len,stdin) ) != -1 ) {
    		//printf("%d\n", riadok);
    		//printf("%s\n", buffer);
    		if (riadok == 1){
    			break;
    		}
    		
    		
    		*array = realloc ( *array, ( *index + 1 ) * sizeof( char* ) );
    		if(*array == NULL)
    			break;
    		
    		array[0][*index] = malloc(riadok + 1);
    		if(array[0][*index])
    			strcpy( array[0][*index], buffer );
    		//else
    		//	printf("Memory Not allocated\n");
    		
    		
    		*index = *index + 1;
    	}
    }