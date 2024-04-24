    int main(void) {
        size_t buffsize = 0;
        char *buffer;
        char input;
        
        buffer = calloc(1, sizeof(char));
        while ((input = getchar()) != '\n') {
            printf("%c\n", input);
            
            /* Incraese the size & realloc */
            ++buffsize;
            buffer = realloc(buffer, (buffsize + 1) * sizeof(char));
            
            if (!buffer) {
                printf("Error reallocating buffer!\n");
                exit(1);
            }
            
            /* Setting the new read char */
            buffer[buffsize - 1] = input;
        }
        
        /* Add the NULL terminator */
        buffer[buffsize] = '\0';
        
        /* Print the result */
        printf("Result = [%s]\n", buffer);
        
        /* Clean */
        free(buffer);
        
        return 0;
    }