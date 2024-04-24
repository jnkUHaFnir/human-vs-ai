              int file_exists(char *filename)
              {
                  struct stat buffer;
                  char fullpath[50], *path = "/home/Nips/";
                  memset(fullpath, 0, sizeof(fullpath));
                  strncat(fullpath, path, strlen(path));
                  int size;
                  size = strlen(path) + strlen(filename);
                  if (size >= 50) {
                      printf("filename too long!\n");
                      return 1;
                  }
                  strncat(fullpath, filename, strlen(filename));
                  int i = stat(filename, &buffer);
                  if (i) {
                      char *etc = "/etc/";
                      memset(fullpath, 0, sizeof(fullpath));
                      strncat(fullpath, etc, strlen(etc));
                      strncat(fullpath, filename, strlen(etc));
                      i = stat(filename, &buffer);
                      if (i) {
                           printf("File not found!\n");
                           return 1;
                     }
                  }
                  return 0;
              }