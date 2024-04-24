#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char program_name[] = "/usr/local/bin/some_program";
  char argument_1[] = "foo";
  char argument_2[] = "foo2";
  char space[] = " ";

  // Make sure to cast the sum of sizes to size_t
  size_t size = (size_t)(strlen(program_name) + strlen(argument_1)+
                             strlen(argument_2) + 2*strlen(space) + 1);

  char *runProgram = malloc(size);

  // Check if the memory allocation was successful
  if (runProgram == NULL) {
    perror("malloc");
    exit(1);
  }

  strcpy(runProgram, program_name);
  strcat(runProgram, space);
  strcat(runProgram, argument_1);
  strcat(runProgram, space);
  strcat(runProgram, argument_2);

  // Check the return value of the system call
  int result = system(runProgram);
  if (result == -1) {
    perror("system");
    free(runProgram);
    exit(1);
  }

  free(runProgram);
  exit(0);
}
