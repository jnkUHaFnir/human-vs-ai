#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *path_cmp1 = "/Users/john/";
  char *path_cmp2 = "foo/bar.txt";

  unsigned len = strlen(path_cmp1) + strlen(path_cmp2) + 1;
  char *path = (char *)malloc(len * sizeof(char));

  if (path == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }

  snprintf(path, len, "%s%s", path_cmp1, path_cmp2);
  
  printf("Combined path: %s\n", path);

  free(path);
  return 0;
}
