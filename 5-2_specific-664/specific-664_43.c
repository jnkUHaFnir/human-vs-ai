#include <stdio.h>
#include <string.h>

typedef struct {
    char word[30];
    int counter;
} WordCountEntry;

int process_stream(WordCountEntry entries[], int entry_count) {
  int line_count = 0; // changed data type to int
  char buffer[30];

  while (fgets(buffer, 30, stdin)) {
    // strtok modifies the input string, so we need to store it before strtok
    char* buffer_copy = strdup(buffer);
    
    char* token = strtok(buffer_copy, " \n");
    while (token != NULL){
      int i = 0;
      while (i < entry_count) { // fixed the loop condition here
        if (!strcmp(entries[i].word, token))
          entries[i].counter++;
        i++;
      }
      token = strtok(NULL, " \n"); // moved token here
      line_count++;
    }
    free(buffer_copy); // free the dynamically allocated copy
  }
  return line_count;
}

int main() {
  WordCountEntry entries[] = {{"cat", 0}, {"nap", 0}, {"dog", 0}};
  int entry_count = sizeof(entries) / sizeof(entries[0]);
  
  printf("Looking for %d words:\n", entry_count);
  
  int count = process_stream(entries, entry_count);
  
  printf("Result:\n");
  for (int i = 0; i < entry_count; i++) {
    printf("%s: %d\n", entries[i].word, entries[i].counter);
  }
  
  return 0;
}
