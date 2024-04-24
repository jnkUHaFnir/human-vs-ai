#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *newChar();
char *addChar(char *, char);
char *readLine(void);

int main() {
  char *palabra;
  palabra = newChar();

  palabra = readLine();
  printf("palabra=%s\n", palabra);

  free(palabra);

  return 0;
}

char *newChar() {
  char *list = (char *)malloc(4 * sizeof(char));
  *list = '\0';
  return list;
}

char *addChar(char *lst, char num) {
  int largo = strlen(lst) + 1;
  lst = realloc(lst, largo * sizeof(char));
  if (lst == NULL) {
    free(lst);
    puts("Error reallocating memory");
    exit(1);
  }
  *(lst + (largo - 1)) = num;
  *(lst + largo) = '\0';
  return lst;
}

char *readLine() {
  char *palabra = newChar();

  fgets(palabra, 4, stdin);
  int length = strlen(palabra);
  while (palabra[length - 1] != '\n') {
    palabra = addChar(palabra, getchar());
    length = strlen(palabra);
  }
  palabra[length - 1] = '\0';

  return palabra;
}
