#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char* getcode(const char *input) 
{ 
  char *p = (char*) input, *buf, *pbuf; 

  if((buf = malloc(256)) == NULL) 
    return NULL; 

  pbuf = buf; 
  while(*p != '\0') { 
    if(strncmp(p, "CODE", 4) == 0) { 
      p += 4; //remove 'code' 

      // Trim white-space after 'code'
      while(*p != '\0' && isspace((unsigned char)*p) != 0) ++p; 

      if(*p != '=')  
       return NULL; 

      ++p; // remove '=' 

      // Trim white-spaces after '=' 
      while(*p != '\0' && isspace((unsigned char)*p) != 0) ++p; 

      // Copy the value until found a '-'  
      while(*p != '\0' && *p != '-') 
        *pbuf++ = *p++; 
    } 

    p++; 
  } 

  // Put 0-terminator. 
  *pbuf = '\0'; 

  return buf; 
} 

int main ()
{
    char buf[255]="CODE=12345-MODE-12453-CODE1-12355";
    
    char* result = getcode(buf);
    
    if(result != NULL)
    {
        printf("Found: %s\n", result);
        free(result); // Don't forget to free the allocated memory
    }
    else
    {
        printf("Code not found\n");
    }
    
    return 0;
}
