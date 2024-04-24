#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int i = 0;
  char line_buffer[BUFSIZ];
  char* words[20];
  FILE *fp = fopen("input.txt", "r");
  
  while (fgets(line_buffer, sizeof(line_buffer), fp)) {
    words[i] = strdup(line_buffer);
    i = i + 1;
  } 
  printf("%d\n", i);
  
  int j = rand() % i;
  int k = (j + 1) % i;
  printf("%s %s\n", words[j], words[k]);
  
  for (int n = 0; n < i; n++) {
    free(words[n]);  // Free the memory allocated for each word
  }
  
  fclose(fp);
  return 0;
}
