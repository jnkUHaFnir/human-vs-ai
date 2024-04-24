#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int a;
  FILE *p_finput = NULL;
  char *filename = NULL;

  if (argc != 2) {
    printf("Usage: %s <input_file>\n", argv[0]);
    return 1;
  }

  filename = malloc(sizeof(char) * (strlen(argv[1]) + 1));
  strncpy(filename, argv[1], strlen(argv[1]));
  filename[strlen(argv[1)] = '\0';

  p_finput = fopen(filename, "r");
  if (p_finput == NULL) {
    printf("Couldn't open %s\n", filename);
    free(filename);
    return 1;
  }

  if (fscanf(p_finput, "%d", &a) != 1) {
    printf("Error reading integer from file.\n");
    fclose(p_finput);
    free(filename);
    return 1;
  }

  printf("a= %d\n", a);

  fclose(p_finput);
  free(filename);
  return 0;
}
