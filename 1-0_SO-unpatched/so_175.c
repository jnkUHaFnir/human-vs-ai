    #include <stdio.h>
    #include <stdlib.h>
    
    int main(void) {
        size_t buffsize = 0;
        char *buffer = NULL;
        char input;
        
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
        
        if (buffsize) {
            buffer[buffsize] = '\0';
            printf("Result = [%s]\n", buffer);
        } else {
            printf("Empty input!\n");
        }
           
        printf("String size=%lu\n", buffsize);
        
        /* Clean */
        free(buffer);
        
        return 0;
    }