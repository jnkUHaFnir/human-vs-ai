#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *addChar(char *, char);
char *readLine(void);

int main() {
  char *palabra;

  palabra = readLine();
  printf("palabra=%s\n", palabra);

  return 0;
}

char *addChar(char *lst, char num) {
  int largo = strlen(lst) + 1;
  char *temp = realloc(lst, largo * sizeof(char));
  if (temp == NULL) {
    // Handle error
    printf("Error: cannot allocate memory\n");
    exit(1);
  }
  lst = temp;
  *(lst + (largo - 1)) = num;
  *(lst + largo) = '\0';
  return lst;
}

char *readLine() {
  char c;
  int size = 1;
  int index = 0;
  char *palabra = malloc(size * sizeof(char));

  if (palabra == NULL) {
    // Handle error
    printf("Error: cannot allocate memory\n");
    exit(1);
  }

  c = getchar();
  while (c != '\n' && c != EOF) {
    if (index == size - 1) {
      size *= 2;
      char *temp = realloc(palabra, size * sizeof(char));
      if (temp == NULL) {
        // Handle error
        printf("Error: cannot allocate memory\n");
        exit(1);
      }
      palabra = temp;
    }
    palabra[index++] = c;
    c = getchar();
  }
  palabra[index] = '\0';
  return palabra;
}
