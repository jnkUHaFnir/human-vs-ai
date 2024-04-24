#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int myArray[240][30] = {0}; // Initialize all elements to zero
  char line[240];
  char *token;
  int i = 0, j = 0;
  FILE *fp;
  
  // Open file for reading
  fp = fopen("array_list.txt", "rt");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Read each line from the file
  while (fgets(line, sizeof(line), fp)) {
    j = 0; // Reset column index for each new row
    token = strtok(line, " ");
    
    while (token != NULL) {
      myArray[i][j] = atoi(token); // Convert token to int and store in array
      printf("%d ", myArray[i][j]); // Print the number
      
      // Get the next token
      token = strtok(NULL, " ");
      j++;
    }

    printf("\n");
    i++;
  }

  // Close the file
  fclose(fp);

  return 0;
}
