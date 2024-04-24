#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char program_name[] = "/usr/local/bin/some_program";
  char argument_1[] = "foo";
  char argument_2[] = "foo2";
  char space[] = " ";
  char *runProgram = malloc(strlen(program_name) + strlen(argument_1) +
                             strlen(argument_2) + 2 * strlen(space) + 1);

  if (runProgram == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  strcpy(runProgram, program_name);
  strcat(runProgram, space);
  strcat(runProgram, argument_1);
  strcat(runProgram, space);
  strcat(runProgram, argument_2);

  printf("Executing: %s\n", runProgram);
  system(runProgram);

  free(runProgram);
  exit(0);
}
