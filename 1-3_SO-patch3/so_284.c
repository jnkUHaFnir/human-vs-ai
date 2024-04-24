    if (strlen(argv[1]) == counter)
	{
        string s = get_string("plaintext: ");
        int len = strlen(s);
        
        string dup = strdup(s); //preserve s by manipulating identical string
        if(dup)
        { 
            for(int i=0;i<len;i++)
            {
    	        if(dup[i]) < 127) dup[i]+=1;
    	        else dup[i] = 1; //skipping NULL and setting to SOH (refer to ASCII table) 
            }
            dup[i] = 0; //adding NULL to end of string 
            printf("ciphertext: %s\n", dup);
            free(dup);
        }
    }