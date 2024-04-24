#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* getcode(const char *input);

#define TRIMSPACES(p) while(*p != '\0' && isspace((unsigned char)*p) != 0) ++p 
#define NSTRIP(p, n) p += n 
#define STRIP(p) ++p 

int main()
{
    char buf[255] = "CODE=12345-MODE-12453-CODE1-12355";
    char *code = getcode(buf);
    
    if (code != NULL) {
        printf("Found code: %s\n", code);
        free(code); // Don't forget to free the allocated memory
    } else {
        printf("Code not found\n");
    }

    return 0;
}

char* getcode(const char *input) 
{ 
    char *p = (char*) input, *buf, *pbuf; 

    if((buf = malloc(256)) == NULL) 
        return NULL; 

    pbuf = buf; 
    while(*p != '\0') { 
        if(strncmp(p, "CODE", 4) == 0) { 
            NSTRIP(p, 4); //remove 'code' 
            TRIMSPACES(p); //trim white-space after 'code' 

            if(*p != '=')  
                return NULL; 

            STRIP(p); // remove '=' 
            TRIMSPACES(p); //trim white-spaces after '=' 

            // copy the value until found a '-'  
            while(*p != '\0' && *p != '-') 
                *pbuf++ = *p++; 
        } 
        p++; 
    } 

    *pbuf = '\0'; //put 0-terminator

    return buf; 
}
