    char* hello(char* name)
    {
	    char *greeting = malloc ( sizeof(char) * 100);
	    strcpy( greeting , "Hello "); //strcpy copies "Hello" to greeting
	    strcat(greeting, name);
	    strcat(greeting, "!\n");
	    printf("%s\n", greeting);
	    return greeting;
    }