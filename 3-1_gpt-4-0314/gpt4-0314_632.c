#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int a;
  FILE * p_finput = NULL;
  char * filename = NULL;

  if (argc < 2) {
      printf("Usage: %s <filename>\n", argv[0]);
      return 1;
  }

  filename = argv[1];

  p_finput = fopen(filename, "r");
  if (p_finput == NULL)
    {
      printf("couldn't open %s \n", filename);
      abort();
    }

  // Use fscanf instead of fread to read the integer value.
  if (fscanf(p_finput, "%d", &a) != 1)
    {
      printf("Error: can't read integer from file %s\n", filename);
      abort();
    }

  printf("a= %d \n", a);  

  fclose(p_finput);
  return 0;
}
