    #include <stdio.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #define NFILES 100;
    typedef struct file  {
      char * name;
      off_t size;
    } file;
    void listFilesRecursively(char *basePath, file ** files, int * size, int * index) 
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
            
            char * pathname = malloc(sz + strlen(dp->d_name) + 2);
            
            if (pathname == NULL) {
              /* out of memory */
              closedir(dir);
              return;
            }
            
            strcpy(pathname, basePath);
            pathname[sz] = '/';
            strcpy(pathname + sz + 1, dp->d_name);
            
            stat(pathname, &buf);
            
            if (S_ISDIR(buf.st_mode)) {
              /* suppose dirs not memorized */
              listFilesRecursively(pathname, files, size, index);
              free(pathname);
            }
            else if (S_ISREG(buf.st_mode)) {
              /* a file, memorize it */
              if (++*index == *size) {
                *size += NFILES;
                *files = realloc(*files, (*size) * sizeof(file));
              }
              
              (*files)[*index].size = buf.st_size;
              (*files)[*index].name = pathname;
            }
            else
              /* bypassed */
              free(pathname);
        }
      }
      
      closedir(dir);
    }
    int compPathname(const void * a, const void * b)
    {
      return strcmp(((file *) a)->name, ((file *) b)->name);
    }
    int main()
    {
      int size = NFILES;
      int index = -1;
      file * files = malloc(size * sizeof(file));
      
      listFilesRecursively(".", &files, &size, &index);
      
      if (index != -1) {
        qsort(files, index + 1, sizeof(file), compPathname);
	
	    /* write and free memory */
        for (int i = 0; i <= index; ++i) {
          printf("%s : %ld\n", files[i].name, (long) files[i].size);
          free(files[i].name);
        }
      }
     
      free(files);
     
      return 0;
    }