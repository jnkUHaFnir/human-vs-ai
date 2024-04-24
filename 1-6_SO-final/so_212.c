    #include <stdio.h>
    #include <stdlib.h>
    
    #define SIZE 50
    int main(void)
    {
            char *str = malloc(SIZE);
    
            str = realloc(str, 25); // now there are 25
            exit(EXIT_SUCCESS);     // bytes allocated for
    }                               // str