#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {

  FILE *fp;
  char *path = NULL;
  size_t len = 0;
  ssize_t read;

  /* Open the command for reading. */
  fp = popen("bash /home/ouhma/myscript.sh", "r");
  if (fp == NULL) {
    printf("Failed to run command\n" );
    exit(1);
  }

  /* Read the output a line at a time - output it. */
  while ((read = getline(&path, &len, fp)) != -1) {
    printf("%s", path);
  }

  /* close */
  pclose(fp);

  free(path); // Don't forget to free the dynamically allocated memory

  return 0;
}
