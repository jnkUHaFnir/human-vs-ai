#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {

  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  
  /* Open the command for reading. */
  fp = popen("bash /home/ouhma/myscript.sh", "r");
  if (fp == NULL) {
    printf("Failed to run command\n" );
    exit(1);
  }

  /* Read the output dynamically line by line. */
  while (getline(&line, &len, fp) != -1) {
    printf("%s", line);
  }

  /* close */
  pclose(fp);
  
  free(line);

  return 0;
}
