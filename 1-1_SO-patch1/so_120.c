    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>
    #include <stdlib.h>
    
    int main(void)
    {
        char cAFirst[25] = {'\0'};
    
        if ( fgets(cAFirst, 25, stdin) == NULL ) {
            if (feof(stdin)) {
                fprintf(stderr, "Abnormal end of input.\n");
                // The contents of the array are not altered
            } 
            if (ferror(stdin)) {
                fprintf(stderr, "A stream error occurred.\n");
                // The contents of the array are indeterminated
            }
            exit(EXIT_FAILURE);
        };
        
        // Length of the maximum initial segment of the array, that consists of
        // only the characters not equal to a newline or null character
        size_t length = strcspn(cAFirst, "\n");
    
        int uc = 0, lc = 0;
        for (size_t i = 0; i < length; i++) {
            unsigned char k = cAFirst[i];
            if ( isupper(k) ) {
                uc++;
            }
            else if ( islower(k) ) {
                lc++;
            }
        }
        printf("Uppercase Letters = %i\nLowercase Letters = %i\n", uc, lc);
                
        return EXIT_SUCCESS;
    }