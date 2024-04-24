#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* getcode(const char *input) {
  char *p = (char*) input, *buf, *pbuf;

  if((buf = malloc(256)) == NULL)
    return NULL;

  pbuf = buf;
  while(*p != '\0') {
    if(strncmp(p, "CODE", 4) == 0) {
      p += 4; // move ahead 4 characters to skip "CODE"

      if(*p != '=') {
        free(buf);
        return NULL;
      }

      p++; // move ahead 1 character to skip "="

      while(*p != '\0' && *p != '-') {
        *pbuf++ = *p++;
      }
      *pbuf = '\0'; // add null terminator to the end of the string
      return buf;
    }
    p++;
  }

  free(buf);
  return NULL;
}

int main() {
  char buffer[255] = "CODE=12345-MODE-12453-CODE1-12355";
  char* code = getcode(buffer);

  if(code != NULL) {
    printf("CODE=%s\n", code); // prints the extracted code
    free(code); // free the allocated memory
  } else {
    printf("CODE not found\n");
  }

  return 0;
}
