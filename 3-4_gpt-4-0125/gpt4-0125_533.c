#include <stdio.h>
#include <string.h>

typedef struct {
  char word[30]; // Assuming each word won't be longer than 29 characters (+1 for null terminator)
  int counter;
} WordCountEntry;

int process_stream(WordCountEntry entries[], int entry_count)
{
  short line_count = 0;
  char buffer[30];

  while (fgets(buffer, 30, stdin)) {
    if (buffer[0] == '.') { // Check if the input is a single period to terminate the input
      break;
    }
    buffer[strcspn(buffer, "\n")] = 0; // Remove the newline character if present
    char* token = strtok(buffer, " ");
    while (token != NULL) {
      for (int i = 0; i < entry_count; i++) { // Iterate through entries to find a match
        if (strcmp(entries[i].word, token) == 0) { // If a match is found, increment the counter
          entries[i].counter++;
        }
      }
      token = strtok(NULL, " "); // Move to the next token
      line_count++;
    }
  }
  return line_count; // You might want to use line_count differently, as it counts tokens rather than lines
}
