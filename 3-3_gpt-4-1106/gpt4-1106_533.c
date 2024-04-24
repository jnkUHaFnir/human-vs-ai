int process_stream(WordCountEntry entries[], int entry_count)
{
  short line_count = 0;
  char buffer[30];

  while (fgets(buffer, 30, stdin)) {
    buffer[strcspn(buffer, "\n")] = 0; // This safely strips the newline character

    char* token = strtok(buffer, " "); // Initial tokenize using only a space delimiter 
    while (token != NULL) {
      for (int i = 0; i < entry_count; i++) { // Should only go up to entry_count
        if (!strcmp(entries[i].word, token)) {
          entries[i].counter++;
          break; // Once you found and incremented the word, you can break the loop
        }
      }
      token = strtok(NULL, " "); // Continue tokenizing the string
      line_count++;
    }
  }
  return line_count;
}
