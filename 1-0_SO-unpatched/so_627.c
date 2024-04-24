        #define TRIMSPACES(p) while(*p != '\0' && isspace((unsigned char)*p) != 0) ++p
        #define NSTRIP(p, n) p += n
        #define STRIP(p) ++p
        
        char* getcode(const char *input, size_t limit)
    {
    	char *p = (char*) input, *buf, *pbuf;
    	size_t i = 0;
    
    	while(*p != '\0') {
    		if(strncmp(p, "CODE", 3) == 0) {
    
    		NSTRIP(p, 4); //remove 'code'
    		TRIMSPACES(p);//trim all white-spaces after 'code'
    		
    		/* check we have a '=' after CODE (without spaces).
    		   if there is not, returns NULL
    		*/
    		if(*p != '=') 
    			return NULL;
    		
    		/* ok. We have.. now we don't need of it
    			just remove it from we output string.
    		*/
    		STRIP(p);
    		
    		/* remove again all white-spaces after '=' */
    		TRIMSPACES(p);
    		
    		/* the rest of string is not valid,
    			because are white-spaces values.
    		*/
    		if(*p == '\0')
    			return NULL;
    		
    		/* allocate space for store the value
    			between code= and -.
    			this limit is set into second parameter.
    		*/
    		if((buf = malloc(limit)) == NULL)
    			return NULL;
    
    	/* copy the value until found a '-' 
    		note: you must be control the size of it, 
    	   for don't overflow. we allocated 256 bytes.
    		if the string is greater it, do implementation with
    		subjecents call to realloc()
    	*/
         pbuf = buf;
          while(*p != '\0' && *p != '-' && i < limit) {
    		*pbuf ++ = *p++; 
    		i ++;
    	}
    	
    	  *pbuf ++ = '\0';
    	  return buf;
    	}
        p ++;
      }
    
      return NULL;
    }