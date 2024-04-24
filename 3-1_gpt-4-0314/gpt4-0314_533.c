int process_stream(WordCountEntry entries[], int entry_count)
{
  short line_count = 0;
  char buffer[100];

  while (fgets(buffer, 100, stdin)) {
    buffer[strlen(buffer) - 1] = '\0';
    char *token = strtok(buffer, " \n");

    while (token != NULL) {
      int i = 0;
      for (i = 0; i < entry_count; ++i) {
        if (!strcmp(entries[i].word, token)) {
          entries[i].counter++;
          break;
        }
      }
      token = strtok(NULL, " \n");
      line_count++;
    }
  }
  return line_count;
}
