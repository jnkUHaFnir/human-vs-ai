        char *token;
        
        for (i=0; i<55; i++)
        {
            fgets(string_array, 80, fp);
        
            //Get the author
            token = strtokstring_array, comma);
            authorName[i] = token;  // or use string copy functions
        
            //Get book name
            while( token != NULL ) 
            {
                printf( " %s\n", token );    //this shall print author name
                token = strtok(NULL, comma);
                bookName[i] = token;
                printf( " %s\n", token );    //this shall print book name
            
                //EDIT: This is additional line after suggestions
                token = strtok(NULL, comma);
            }
        }