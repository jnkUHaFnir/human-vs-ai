    printf("Enter 'string1'\n");
    if ( scanf("%s", string1) != 1 )
    {
       // Problem reading into string1.
       printf("Unable to read string1\n");
    }
    printf("Enter 'string2'\n");
    if ( scanf("%s", string2) != 1 )
    {
       // Problem reading into string2.
       printf("Unable to read string2\n");
    }
    printf("Input strings...\nstring1: \"%s\", string2: \"%s\"\n", string1, string2);