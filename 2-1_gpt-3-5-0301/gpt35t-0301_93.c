#include <stdio.h>

int main() {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while ((read = getline(&line, &len, stdin)) != -1) {
    printf("Retrieved line of length %zu:\n", read);
    printf("%s", line);
  }

  free(line);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 10

int main() {
  char *line = NULL;
  size_t len = 0;

  while (1) {
    int c;
    int i = 0;

    line = (char *)realloc(line, len + CHUNK_SIZE + 1);

    while ((c = getchar()) != EOF && c != '\n') {
      if (i == CHUNK_SIZE) {
        len += CHUNK_SIZE;
        line = (char *)realloc(line, len + CHUNK_SIZE + 1);
        i = 0;
      }
      line[len + i] = c;
      i++;
    }

    line[len + i] = '\0';

    if (strlen(line) == 0) {
      break;
    }

    printf("Retrieved line:\n");
    printf("%s", line);

    len = 0;
    free(line);
    line = NULL;
  }

  return 0;
}
