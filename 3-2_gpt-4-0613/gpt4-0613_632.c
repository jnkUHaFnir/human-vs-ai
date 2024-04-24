#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int a, flag_scanf;
  FILE * p_finput = NULL;
  char * filename = NULL;

  filename = malloc(sizeof(char) * (strlen(argv[1]) + 1));
  strncpy(filename, argv[1],strlen(argv[1]));
  filename[strlen(argv[1])] = '\0';

  p_finput = fopen(filename, "r");
  if (p_finput == NULL)
    {
      printf("couldn't open %s \n", filename);
      abort();
    }


  flag_scanf = fscanf(p_finput, "%d", &a);

  printf("a= %d \n", a);  

  fclose(p_finput);
  free(filename);
  return 0;
}
