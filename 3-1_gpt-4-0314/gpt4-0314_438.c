#include <stdio.h>
#include <stdlib.h>

int main() {
  int exit_status = system("which Rscript >/dev/null 2>&1");
  if (exit_status == 0) {
    printf("Rscript is installed\n");
  } else {
    printf("Rscript is not installed\n");
  }
  return 0;
}

This code will print "Rscript is installed" if the command "which Rscript" is successful, and "Rscript is not installed" otherwise.

Note that using "system()" may be considered insecure in some cases. If you need a more secure and robust approach, consider using the "exec()" family of functions together with some file system functions to search for the executable in the PATH directories.
