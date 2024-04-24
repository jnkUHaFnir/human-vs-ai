    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    int main(int argc, char **argv)
    {
      char **array[128][128];
      int    size;
      int    i, j;
      if (1 == argc || 0 >= (size = atoi(argv[1])))
        fprintf(stderr, "usage: %s <num>; where num > 0\n", argv[0]), exit(-1);
      for (i = 0; i < 128; ++i)
       	for (j = 0; j < 128; ++j)
          if (NULL == (array[i][j] = malloc(size * sizeof(char*))))
          {
            fprintf(stderr, "malloc failed when i = %d, j = %d\n", i, j);
            perror(NULL);
            return -1;
          }
      sleep(10);
      return 0;
    }