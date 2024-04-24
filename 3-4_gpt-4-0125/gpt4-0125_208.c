#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char program_name[] = "/usr/local/bin/some_program";
  char argument_1[] = "foo";
  char argument_2[] = "foo2";
  char space[] = " ";
  
  // Calculate total length for the command string
  size_t totalLength = strlen(program_name) + strlen(argument_1) + 
                       strlen(argument_2) + 2*strlen(space) + 1;
  
  char *runProgram = malloc(totalLength);

  // Check if malloc was successful
  if(runProgram == NULL) {
    perror("Failed to allocate memory");
    exit(EXIT_FAILURE);
  }
  
  strcpy(runProgram, program_name);
  strcat(runProgram, space);
  strcat(runProgram, argument_1);
  strcat(runProgram, space);
  strcat(runProgram, argument_2);

  // Uncomment the next line if you're debugging on a shell that supports redirection.
  // strcat(runProgram, " 2>&1"); // Append stderr redirection to stdout for more verbose errors.

  system(runProgram);
  free(runProgram);
  exit(0);
}
