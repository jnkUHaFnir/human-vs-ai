    char *orig_splitString, *splitString;
    /*...*/
    orig_splitString = splitString = (char*)malloc(100*sizeof(char));
    /*...*/
    splitString = strtok(buffer, delim);
    /*...*/
    free(orig_splitString); 
``` 

This way, `orig_splitString` will always point to the allocated memory and you will still be able to modify and use `splitString` inside your loop. When you're done you can correctly free the memory using `orig_splitString`.
