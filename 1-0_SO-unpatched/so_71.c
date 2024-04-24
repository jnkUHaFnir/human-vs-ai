    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    
    void someFunc (char* s1) {
        
        const char* s2 = "hello ";
        
        size_t s1len = strlen(s1);
        size_t s2len = strlen(s2);
        size_t totalLength = s1len + s2len;
        
        char * strBuf = malloc(totalLength + 1);
        
        strcpy(strBuf, s2);
        strcpy(strBuf + s2len, s1);
        
        printf("%s \n", strBuf);
        
        free(strBuf);
        
    }
    
    int main (void) {
        
        char *s = "blah blah";
        
        someFunc(s);
        
        return 0;
    }