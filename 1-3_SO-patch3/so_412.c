              int file_exists(char *filename)
              {
                  struct stat buffer;
                  char fullpath[50], *path = "/home/Nips/";
                  strcat(fullpath, path);
                  strcat(fullpath, filename);
                  int i = stat(filename, &buffer);
                  if (i) {
                      memset(fullpath, 0, sizeof(fullpath));
                      strcat(fullpath, "/etc");
                      strcat(fullpath, filename);
                      i = stat(filename, &buffer);
                      if (i) {
                           printf("File not found!\n");
                           return 1;
                     }
                  }
                  return 0;
              }