    #include <string.h>
    #include <stdio.h>
    
    void someFunc (char* s1) {
        
        char* s2;
        
        s2 = "hello ";
        
        size_t lenToAppend = strlen(s1);
        size_t totalLenght = strlen(s1) + strlen(s2);
        
        char s3[totalLenght];
        
        strcpy(s3, s2);
        
        strncat(s3, s1, lenToAppend);
        
        printf("%s \n", s3);
    }
    
    int main (void) {
        
        char *s = "blah blah";
        
        someFunc(s);
        
        return 0;
    }