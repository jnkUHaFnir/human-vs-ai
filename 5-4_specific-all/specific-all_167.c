#include <stdio.h>
#include <stdlib.h>

int main() {
  int myArray[240][30];
  char line[240];
  char *token;
  int i, n, j;
  FILE *fp;
  fp = fopen("array_list.txt", "rt");
  if (fp == NULL) {
    fprintf(stderr, "File open failed.\n");
    return 1;
  }

  j = 0;
  i = 0;
  while (fgets(line, sizeof(line), fp)) {
    token = strtok(line, " ");
    j = 0;
    while (token != NULL) {
      n = atoi(token);
      myArray[i][j] = n;
      printf("%d ", myArray[i][j]);
      token = strtok(NULL, " ");
      j++;
    }

    printf("\n");
    i++;
  }

  fclose(fp);
  return 0;
}
