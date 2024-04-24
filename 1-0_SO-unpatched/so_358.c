    char array[1000];
    if( 1 != scanf("%999s",array) ){
       fprintf(stderr,"Error in input\n");
       exit(EXIT_FAILURE);
    }
    size_t len = strlen(array);
    for( size_t i = 0; i < len; i++ ){
       if( array[i] == 'A' ){
          ...
       } 
       else if( .. ){
    
       }
    }