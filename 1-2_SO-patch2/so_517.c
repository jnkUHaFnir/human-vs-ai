    #include <stdio.h>
    #include <stdlib.h>
    int main( int argc, char *argv[] ) {
      FILE *fp;
      size_t s = 1;
      char * path = malloc(s);
      if (NULL == path)
      {
        perror("malloc() failed");
        return EXIT_FAILURE);
      }
      path[0] = '\0';
      /* Open the command for reading. */
      fp = popen("bash /home/ouhma/myscript.sh", "r");
      if (NULL == fp) 
      {
        perror("popen() failed");
        return EXIT_FAILURE);
      }
      {
        char buffer[1024];
        /* Read the output a line at a time - output it. */
        while (NULL != fgets(buffer, sizeof buffer, fp)) {
          fprintf(stderr, "partly read: '%s'\n", buffer);
        
          while ((s - 1) < strlen(buffer))
          {
            void * p = realloc(path, s *= 2); /* Grow s exponentially. */
            if (NULL == p)
            {
              perror("realloc() failed");
              return EXIT_FAILURE;
            }
            path = p;
          }
          /* Concatenate what just had been read to final "string". */
          strcat(path, buffer);
        }
      }
      if (!feof(fp))
      {
        perror("fgets() failed");
      }
      /* Close file. */
      pclose(fp);
      /* Print result. */
      printf("read: '%s'", path);
      /* Clean up. */
      free(path);
      return EXIT_SUCCESS;
    }