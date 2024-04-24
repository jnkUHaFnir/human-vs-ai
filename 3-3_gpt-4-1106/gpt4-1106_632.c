#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int a;
  char *filename;
  FILE *p_finput;

  if(argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  filename = argv[1]; // No need to copy the filename using malloc

  p_finput = fopen(filename, "r");
  if (p_finput == NULL) {
    printf("couldn't open %s \n", filename);
    return 1;
  }

  // fscanf: Reads formatted input from a stream
  if (fscanf(p_finput, "%d", &a) != 1) {
      printf("Failed to read an integer from the file\n");
      fclose(p_finput);
      return 1;
  }

  printf("a= %d \n", a);  

  fclose(p_finput);
  return 0;
}
