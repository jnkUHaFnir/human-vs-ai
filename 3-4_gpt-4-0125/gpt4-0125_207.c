#include <stdio.h>
#include <stdlib.h>    
#include <string.h>
#include <time.h>

char* concat(const char *s1, const char *s2)
{
    //+1 for the zero-terminator
    char *result = (char *)malloc(strlen(s1)+strlen(s2)+1); 
    // Always check if malloc was successful
    if(result == NULL) {
        perror("Unable to allocate memory for the result.");
        exit(EXIT_FAILURE);
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main ()
{
  srand(time(NULL));
  int r = rand() % 1000000; // To ensure it's a 6 digit number

  // Make room for 6 digits, '-' and '\0'
  char randomStr[7];
  
  // Ensure the number is exactly 6 digits
  sprintf(randomStr, "%06d", r); // Formats the int as a 6-digit string
  
  char* finalStr = concat("foo-", randomStr);
  
  // Always check if the concatenation was successful
  if(finalStr != NULL) {
    printf("%s\n", finalStr);
    // Don't forget to free the memory to avoid memory leaks!
    free(finalStr);
  }
  
  return 0;
}
