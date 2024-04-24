#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[] ) {

  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  /* Open the command for reading. */
  fp = popen("bash /home/ouhma/myscript.sh", "r");
  if (fp == NULL) {
    printf("Failed to run command\n" );
    exit(1);
  }

  /* Read the output a line at a time - output it. */
  while ((read = getline(&line, &len, fp)) != -1) {
    printf("%s", line);
  }

  /* cleanup */
  pclose(fp);
  if (line) {
    free(line);
  }

  return 0;
}
