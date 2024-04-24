char *readline(FILE *fp, char *buffer) {
  char ch;
  int i = 0, buff_len = 0;

  buffer = malloc(1); // start with a small buffer

  while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
    buffer[i] = ch;
    ++i;
    ++buff_len;
    buffer = realloc(buffer, buff_len + 1); // increase buffer size by 1
  }

  buffer[i] = '\0'; // add null terminator
  return buffer;
}
