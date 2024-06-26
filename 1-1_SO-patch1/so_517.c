    #include <stdlib.h>
    #include <stdio.h>
    #define BUFFER_SIZE (1024)
    #define START_SIZE (1) /* Has to be > 0 */
    int main( int argc, char *argv[] ) 
    {
      size_t s = START_SIZE ;
      char * path = malloc(s);
      if (NULL == path)
      {
        perror("malloc() failed");
        return EXIT_FAILURE);
      }
      path[0] = '\0';
      {
        /* Open the command for reading. */
        FILE * fp = popen("bash /home/ouhma/myscript.sh", "r");
        if (NULL == fp) 
        {
          perror("popen() failed");
          return EXIT_FAILURE);
        }
        {
          char buffer[BUFFER_SIZE];
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
        if (-1 == pclose(fp))
        {
          perror("pclose() failed");
        }
      }
      /* Print result. */
      printf("read: '%s'\n", path);
      /* Clean up. */
      free(path);
      return EXIT_SUCCESS;
    }