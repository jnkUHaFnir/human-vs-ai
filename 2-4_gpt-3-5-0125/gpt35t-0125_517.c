#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {

  FILE *fp;
  char c;

  /* Open the command for reading. */
  fp = popen("bash /home/ouhma/myscript.sh", "r");
  if (fp == NULL) {
    printf("Failed to run command\n" );
    exit(1);
  }

  /* Read the output character by character and print it. */
  while ((c = fgetc(fp)) != EOF) {
    printf("%c", c);
  }

  /* close */
  pclose(fp);

  return 0;
}
