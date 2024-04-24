    int len = strlen(s);
    if (strlen(argv[1]) == counter)
	{
        for(int i=0;i<len;i++)
        {
    	    if(s[i]) < 127) s[i]+=1;
    	    else s[i] = 1; //skipping NULL and setting to SOH (refer to ASCII table) 
        }
        s[i] = 0; //adding NULL to end of string 
        printf("ciphertext: %s\n", s + 1);
    }