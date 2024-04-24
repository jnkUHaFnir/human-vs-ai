    void insert(char *str, char input, int n) {
    
        str = realloc(str, n + 2); /* realloc first */
         
        if(!str) /* realloc failed */
        {
            fputs("realloc failed", stderr);
            return;
        }
    
        int i;
    
        for (i = n; i > 0; i++) {
            str[i] = str[i + 1]; /* Move all characters up */ 
        }
    
        str[0] = input; /* Insert the new character */
    
        printf("%s", str); /* Print the new string */
    }