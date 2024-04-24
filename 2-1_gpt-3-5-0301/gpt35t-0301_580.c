#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE* file = fopen("data.txt", "r");
  if (!file) {
    printf("Error: could not open file\n");
    return 1;
  }

  char* word = NULL;
  int wordSize = 0;
  char line[256];

  while (fgets(line, sizeof(line), file)) {
    char* p = line;
    while (*p) {
      // skip over leading whitespace
      while (*p && (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')) {
        p++;
      }

      // find end of word
      char* q = p;
      while (*q && (*q != ' ' && *q != '\t' && *q != '\r' && *q != '\n')) {
        q++;
      }

      // copy word to buffer
      int len = q - p;
      if (len > 0) {
        if (wordSize < len + 1) {
          wordSize = len + 1;
          word = realloc(word, wordSize);
        }
        strncpy(word, p, len);
        word[len] = '\0';
        printf("%s\n", word);
      }

      // advance to next word
      p = q;
    }
  }

  free(word);
  fclose(file);

  return 0;
}
