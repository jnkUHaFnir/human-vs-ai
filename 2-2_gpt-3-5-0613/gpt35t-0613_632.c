#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int a;
  FILE *p_finput = NULL;
  char *filename = NULL;

  // Check if the filename is provided as a command-line argument
  if (argc < 2)
  {
    printf("Filename not provided.\n");
    return 1;
  }

  filename = argv[1];

  p_finput = fopen(filename, "r");
  if (p_finput == NULL)
  {
    printf("Couldn't open %s \n", filename);
    return 1;
  }

  // Read the integer from the file
  if (fscanf(p_finput, "%d", &a) != 1)
  {
    printf("Failed to read the integer from the file.\n");
    return 1;
  }

  printf("a = %d\n", a);  

  fclose(p_finput);

  return 0;
}
