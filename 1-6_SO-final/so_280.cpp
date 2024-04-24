    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    int main(int argc, char **argv)
    {
      if (argc == 1)
        fprintf(stderr, "usage: %s <num>; where num > 0\n", argv[0]), exit(-1);
      int size = atoi(argv[1]);
      if (size <= 0)
        fprintf(stderr, "usage: %s <num>; where num > 0\n", argv[0]), exit(-1);
      char **array[1024][1024];
      int i, j;
      for (i = 0; i < 1024; ++i)
      {
       	for (j = 0; j < 1024; ++j)
        {
          if (NULL == (array[i][j] = malloc(size * sizeof(char*))))
          {
            fprintf(stderr, "malloc failed when i = %d, j = %d\n", i, j);
            perror(NULL);
            return -1;
          }
        }
      }
      sleep(10);
      return 0;
    }