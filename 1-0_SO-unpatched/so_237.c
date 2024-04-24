    void insert(char *str, char input, int n) {
    
        char* temp = str;
        int i;
        str = realloc(str, n + 2); /* realloc first */
    
        if(!str) /* realloc failed */
        {
            fputs("realloc failed", stderr);
            free(temp); /* Free the previously malloc-ed memory */
            exit(-1); /* Exit the program */
        }
    
        for (i = n; i >= 0; i--) {
            str[i + 1] = str[i]; /* Move all characters up */ 
        }
    
        str[0] = input; /* Insert the new character */
    
        printf("%s", str); /* Print the new string */
    }