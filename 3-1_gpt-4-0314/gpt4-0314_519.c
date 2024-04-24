int sgetline(int fd, char **out) {
  int buf_size = 128;
  int length = 0;
  char buf[1];
  char *buffer = malloc(buf_size);
  char *newbuf;
  int size = buf_size;

  assert(NULL != buffer);

  while (read(fd, buf, 1) > 0) {
    buffer[length++] = buf[0];

    if (buf[0] == '\n') {
      buffer[length] = '\0';
      *out = buffer;
      return length;
    }

    if (length >= size) {
      size += buf_size;
      newbuf = realloc(buffer, size);

      if (NULL != newbuf) {
        buffer = newbuf;
      } else {
        printf("sgetline() allocation failed!\n");
        exit(1);
      }
    }
  }

  *out = buffer;
  return length;
}
char *tbuf;
while (sgetline(sockfd, &tbuf) > 0) {
  printf("%s", tbuf); // Print the read line for debugging purposes
  if (strcmp(tbuf, "\r\n") == 0) {
    printf("End of Headers detected.\n");
    break;
  }
}
