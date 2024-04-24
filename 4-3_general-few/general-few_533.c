int process_stream(WordCountEntry entries[], int entry_count) {
  int line_count = 0;
  char buffer[30];

  while (fgets(buffer, 30, stdin)) {
    buffer[strcspn(buffer, "\n")] = '\0'; // Removing the new line character

    char* token = strtok(buffer, " ");
    while (token != NULL) {
      int i = 0;
      while (i < entry_count) {
        if (strcmp(entries[i].word, token) == 0) {
          entries[i].counter++;
        }
        i++;
      }
      token = strtok(NULL, " ");
    }
    line_count++;
  }
  return line_count;
}
