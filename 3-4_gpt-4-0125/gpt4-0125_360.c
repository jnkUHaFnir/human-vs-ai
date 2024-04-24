#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* getcode(const char *input) 
{ 
  const char *p = input;
  char *buf, *pbuf; 

  // Allocate a buffer to hold the found code
  if((buf = malloc(256)) == NULL) 
    return NULL; 

  pbuf = buf; 
  while(*p != '\0') {
    // Compare if the current substring is "CODE="
    if(strncmp(p, "CODE=", 5) == 0) { 
      p += 5; // Skip "CODE="

      // Copy the digits until a '-' is found or end of string
      while(*p != '\0' && *p != '-') 
        *pbuf++ = *p++; 

      // Successfully copied, break from the loop
      break;
    } 
    // Move to the next character
    p++; 
  } 

  // Put 0-terminator to terminate the string
  *pbuf = '\0'; 

  // If no code was copied, free the buffer and return NULL
  if(buf[0] == '\0') {
    free(buf);
    return NULL;
  }

  // Return the found code
  return buf; 
} 

int main() {
  char buf[255] = "CODE=12345-MODE-12453-CODE1-12355";
  char* code = getcode(buf);
  if (code) {
    printf("Found CODE: %s\n", code);
    free(code); // Remember to free the allocated memory!
  } else {
    printf("CODE not found.\n");
  }
  return 0;
}
