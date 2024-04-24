    char* hello(char* name)
    { 
		char hello[] = "Hello ";
		char excla[] = "!\n";
		char *greeting = malloc ( sizeof(char) * ( strlen(name) + strlen(hello) + strlen(excla) + 1 ) );
		strcpy( greeting , hello);
		strcat(greeting, name);
		strcat(greeting, excla);
	    return greeting;
    }