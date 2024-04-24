char *readline(FILE *fp, char *buffer) {
  char ch;
  int i = 0, buff_len = 0;

  // Allocate initial memory for buffer
  buffer = malloc(buff_len + 1);  // +1 for null terminator

  while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
    ++buff_len;
    buffer = realloc(buffer, buff_len + 1);  // +1 for null terminator

    buffer[i] = ch;
    ++i;
  }

  buffer[i] = '\0';  // Null terminate the buffer

  return buffer;
}
