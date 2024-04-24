#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  FILE *fp = fopen("file.txt","r");
  if (!fp) {
    perror("Error opening file");
    return 1;
  }

  char string[100];        // Removed the 'const' as we are modifying the string
  const char fetch[] = "learning";

  while(fgets(string, 100, fp)) {
    char *result = strstr(string, fetch); // Search for the word within the fetched string
    if(result != NULL) { // Check if the word is found
      printf("Your result is: %s", result); // Print the sentence from the word onwards
      break; // Break the loop if the word is found
    }
  }
  
  fclose(fp); // Close the file after you're done with it
  return 0;
}
