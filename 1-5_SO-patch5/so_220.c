    int n,m;
    printf( "Enter two digits" );
    scanf( "%d %d", &m, &n );
    int size = sizeof( int ) * n * m;
    int * arr = (int *) malloc( size );    
    if ( arr == NULL ) { 		
		perror("malloc");
		exit(EXIT_FAILURE);
	}
    for( int i = 0; i < m * n; i++ ) {
    	scanf( "%d", arr + i );
    }
    for( int i=0; i<n*m; i++ ){
    	printf( "%d", *( arr + i ) );
    }