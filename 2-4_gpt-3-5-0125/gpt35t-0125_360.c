#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* getcode(const char *input) 
{ 
    char *p = (char*) input, *buf, *pbuf; 

    if((buf = malloc(256)) == NULL) 
        return NULL; 

    pbuf = buf; 
    while(*p != '\0') { 
        if(strncmp(p, "CODE", 4) == 0) { 
            p += 4; // remove 'CODE'
            while (*p != '=')
            {
                p++;
            }
            p++; // remove '='

            while(*p != '\0' && *p != '-') {
                *pbuf++ = *p++; 
            }
            break; 
        }
        p++; 
    } 

    *pbuf = '\0'; 

    return buf; 
} 

int main() 
{
    char buffer[255]="CODE=12345-MODE-12453-CODE1-12355";
    char* code = getcode(buffer);
    
    if (code) {
        printf("CODE=%s\n", code);
        free(code);
    } else {
        printf("CODE not found\n");
    }

    return 0;
}
