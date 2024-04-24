#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char program_name[] = "/usr/local/bin/some_program";
  char argument_1[] = "foo";
  char argument_2[] = "foo2";
  char space[] = " ";

  // Calculate the required size for the final string
  int total_size = snprintf(NULL, 0, "%s %s %s %s", program_name, argument_1, space, argument_2);
  
  // Allocate memory for the final string
  char *runProgram = malloc(total_size + 1);
  
  // Construct the final string using snprintf
  snprintf(runProgram, total_size + 1, "%s %s %s %s", program_name, argument_1, space, argument_2);

  system(runProgram);
  free(runProgram);
  exit(0);
}
