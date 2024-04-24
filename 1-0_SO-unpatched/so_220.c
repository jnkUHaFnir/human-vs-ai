    int n,m;
	printf( "Enter two digits" );
	int scanCount = scanf( "%d %d", &m, &n );
	if( scanCount < 2 ){   
	    perror("Input");
		exit(EXIT_FAILURE);   
	}
	scanCount = 0;
	size_t size = sizeof( int ) * n * m;
	int * arr = (int *) malloc( size );
	if ( arr == NULL ) { 
		perror("malloc");
		exit(EXIT_FAILURE);
	};
	for( int i = 0; i < m * n; i++ ){
		if ( scanf( "%d", arr + i ) )
		    scanCount++;
	}
	if( scanCount < m*n ){   
	    perror("Input");
		exit(EXIT_FAILURE);
	}
	for( int i=0; i<n*m; i++ ){
		printf( "\nValue at %d : %d\n", i, *( arr + i ) );
	}