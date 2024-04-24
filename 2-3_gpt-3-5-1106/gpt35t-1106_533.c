int process_stream(WordCountEntry entries[], int entry_count)
{
  short line_count = 0;
  char buffer[30];

  while (fgets(buffer, 30, stdin)) {
    buffer[strlen(buffer)-1]='\0';
    char* token = strtok(buffer, " \n");
    while (token != NULL){
      int i = 0;
      while (i < entry_count) {
        if (!strcmp(entries[i].word, token))
          entries[i].counter++;
        i++;
      }
      token = strtok(NULL, " \n"); // Move to the next token
      line_count++;
    }
  }
  return line_count;
}
