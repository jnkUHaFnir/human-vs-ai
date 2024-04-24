#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char word[30];
  int counter;
} WordCountEntry;

int process_stream(WordCountEntry entries[], int entry_count)
{
  int line_count = 0;
  char buffer[100];

  while (fgets(buffer, 100, stdin)) {
    char* token = strtok(buffer, " \n");
    while (token != NULL) {
      for (int i = 0; i < entry_count; i++) {
        if (strcmp(entries[i].word, token) == 0) {
          entries[i].counter++;
        }
      }
      token = strtok(NULL, " \n");
      line_count++;
    }
  }
  return line_count;
}

int main(int argc, char *argv[]) {
  int i, count;
  WordCountEntry entries[argc-1];

  printf("Looking for %d words\n", argc - 1);
  for (i = 1; i < argc; i++) {
    strcpy(entries[i-1].word, argv[i]);
    entries[i-1].counter = 0;
  }

  printf("Looking for words:\n");
  count = process_stream(entries, argc-1);

  printf("Result:\n");
  for (i = 0; i < argc-1; i++) {
    printf("%s: %d\n", entries[i].word, entries[i].counter);
  }

  return 0;
}
