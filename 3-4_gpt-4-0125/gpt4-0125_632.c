#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int a;
  FILE * p_finput = NULL;
  char * filename = NULL;

  // Ensure there is an argument for the filename
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  filename = malloc(sizeof(char) * (strlen(argv[1]) + 1));
  if (filename == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return EXIT_FAILURE;
  }

  strncpy(filename, argv[1], strlen(argv[1]) + 1); // +1 to include the null terminator

  p_finput = fopen(filename, "r");
  if (p_finput == NULL)
  {
    printf("couldn't open %s \n", filename);
    free(filename);
    return EXIT_FAILURE;
  }

  // Use fscanf to read an integer from the file
  if (fscanf(p_finput, "%d", &a) != 1) {
    fprintf(stderr, "Failed to read an integer from the file\n");
    fclose(p_finput);
    free(filename);
    return EXIT_FAILURE;
  }

  printf("a= %d \n", a);

  fclose(p_finput);
  free(filename);
  return EXIT_SUCCESS;
}
