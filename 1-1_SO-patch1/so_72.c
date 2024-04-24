    #include <string.h>
    #include <stdio.h>
    
    void someFunc (char* s1) {
        
        char* s2;
        
        s2 = "hello ";
        
        size_t lenToAppend = strlen(s1);
        size_t totalLength = lenToAppend + strlen(s2) + 1;
        
        char s3[totalLength];
        
        strcpy(s3, s2);
        
        strncat(s3, s1, lenToAppend);
        s3[totalLength-1] = 0;
        
        printf("%s \n", s3);
    }
    
    int main (void) {
        
        char *s = "blah blah";
        
        someFunc(s);
        
        return 0;
    }