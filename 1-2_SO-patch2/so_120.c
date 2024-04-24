    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>
    #include <stdlib.h>
    
    int main(void)
    {
        char cAFirst[25] = {'\0'};
    
        if ( fgets(cAFirst, 25, stdin) == NULL ) {
            if (feof(stdin))
                fprintf(stderr, "Abnormal end of input.\n");  
            if (ferror(stdin))
                fprintf(stderr, "A stream error occurred.\n");
            exit(EXIT_FAILURE);
        };
        
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
        printf("Uppercase Letters=%i \nLowercase Letters=%i \n",uc,lc );
                
        return 0;
    }