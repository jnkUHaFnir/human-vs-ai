char * readline(FILE *fp, char *buffer) {
  char ch;
  int i = 0, buff_len = 1;

  buffer = malloc(buff_len);

  while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
    buffer[i] = ch;
    ++i;
    
    buffer = realloc(buffer, buff_len + 1);
    ++buff_len;
  }

  buffer[i] = '\0'; // Add null terminator at the end of the string

  return buffer;
}
