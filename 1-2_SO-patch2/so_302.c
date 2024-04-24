    void load(char ***array,int *index) { //Use pointer to pointer to pointer
    
        int riadok;
        size_t len = 0;
        char *buffer = NULL;
    
        printf("Slova:\n");
        while( ( riadok = getline(&buffer,&len,stdin) ) != -1 ) {
    
            if (riadok == 1){
                break;  
            }
            
            array = malloc(sizeof(char**));
            *array = malloc (( *index + 1 ) * sizeof( char* ));
            *array[*index] = malloc ( (riadok + 1) * sizeof(char*) );
            strcpy( *array[*index], buffer );
    
            *index = *index + 1; 
      } 
    }