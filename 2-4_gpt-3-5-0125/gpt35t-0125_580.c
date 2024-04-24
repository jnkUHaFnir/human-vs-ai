#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  FILE* InputWords = fopen("ListOfWords.txt", "r");
  if (InputWords == NULL) {
    printf("Error while opening the file.\n");
    return 1;
  }

  while ((read = getline(&line, &len, InputWords)) != -1) {
    char *word;
    char *ptr = line;

    while (sscanf(ptr, "%*[^a-zA-Z]%ms", &word) == 1) {
      printf("%s\n", word);
      free(word);
      ptr += strlen(word);
    }
  }

  fclose(InputWords);
  if (line) free(line);

  return 0;
}
