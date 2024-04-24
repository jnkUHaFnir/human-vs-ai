    char delim[] = {" \n\t"};  //or whatever delimitors you need
    char *tok = 0;
    
    tok = strtok(stringToParse, delim);  
    while(tok)
    {
        //do something with tok
        ...
        //get next token:
        tok = strtok(NULL, delim);
    }