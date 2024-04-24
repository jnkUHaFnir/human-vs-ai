    #define TRIMSPACES(p) while(*p != '\0' && isspace((unsigned char)*p) != 0) ++p
    #define NSTRIP(p, n) p += n
    #define STRIP(p) ++p
    
    char* getcode(const char *input)
    {
      char *p = (char*) input, *buf, *pbuf;
      
      
      pbuf = buf;
      while(*p != '\0') {
        if(strncmp(p, "CODE", 3) == 0) {
    
          NSTRIP(p, 4); //remove 'code'
          TRIMSPACES(p);//trim white-space after 'code'
    
         if(*p != '=') 
           return NULL;
          
          STRIP(p); // remove '='
          TRIMSPACES(p); //trim white-spaces after '='
    
        if((buf = malloc(256)) == NULL)
           return NULL;
    
    /* copy the value until found a '-' 
       note: you must be control the size of it, 
       for don't extoure we allocated size, that's 256
       or do subjecents call to realloc()
    */
         pbuf = buf;
          while(*p != '\0' && *p != '-')
    	*pbuf ++ = *p++;
    
          break;
        }
        p ++;
      }
    
    //put 0-terminator.
      *pbuf ++ = '\0';
    
      return buf;
    }