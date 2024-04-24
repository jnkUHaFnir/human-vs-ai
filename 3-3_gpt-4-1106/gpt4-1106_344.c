#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  srand((unsigned int)time(NULL)); // Initialize random number generator.

  int i = 0;
  char line_buffer[BUFSIZ];
  char* words[20]; // Assuming we will not have more than 20 lines.
  FILE *fp = fopen("input.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }
  
  while (fgets(line_buffer, sizeof(line_buffer), fp)) {
    words[i] = strdup(line_buffer); // Allocate memory and copy the string.
    if (words[i] == NULL) {
      perror("strdup failed");
      return 1;
    }
    //Remove the newline character at the end if present
    size_t len = strlen(words[i]);
    if (len > 0 && words[i][len-1] == '\n') {
      words[i][len-1] = '\0';
    }
    i++;
    if (i >= 20) {
      break; // Avoid going out of bounds of the 'words' array.
    }
  }
  fclose(fp);

  // Check for empty file
  if (i == 0) {
    printf("The file is empty.");
    return 1;
  }

  printf("Total lines read: %d\n", i);
  int j = rand() % i; // Use 'i' since that's the actual number of lines read.
  int k;
  do {
    k = rand() % i;
  } while (k == j); // Ensure k is different from j.

  printf("%s %s\n", words[j], words[k]); 

  // Clean up the allocated memory
  for (int index = 0; index < i; index++) {
    free(words[index]);
  }

  return 0;
}
