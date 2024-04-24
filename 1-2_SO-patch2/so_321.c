    void listFilesRecursively(char *basePath) 
    {
      DIR *dir = opendir(basePath);
      
      if (!dir) 
        return;
      
      struct dirent *dp;
      struct stat buf;
      
      while ((dp = readdir(dir)) != NULL)
      {
        if ((strcmp(dp->d_name, ".") != 0) && (strcmp(dp->d_name, "..") != 0))
        {
            size_t sz = strlen(basePath);
            
            char * path = malloc(sz + strlen(dp->d_name) + 2);
            
            if (path == NULL) {
              /* out of memory */
              closedir(dir);
              return;
            }
            
            strcpy(path, basePath);
            path[sz] = '/';
            strcpy(path + sz + 1, dp->d_name);
            
            stat(path, &buf);
            printf("%s %ld bytes\n", path, buf.st_size);
    
            /* save path and buf.st_size somewhere is you want */
            listFilesRecursively(path);
            
            free(path); /* only because I do not save it somewhere */
        }
      }
      
      closedir(dir);
    }