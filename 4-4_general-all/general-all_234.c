#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _SPerson {
  char *name;
  char *surname;
  char *id;
  char *telephone;
} SPerson;

int Load(SPerson Archive[], unsigned int *ne) {
  int i = 0;
  char s[4][20];
  FILE *f;
  f = fopen("archive.txt", "r");
  if (f == NULL) return 0;

  while (fscanf(f, "%19s %19s %19s %19s", s[0], s[1], s[2], s[3]) == 4) {
    Archive[i].id = malloc(strlen(s[0]) + 1);
    strcpy(Archive[i].id, s[0]);

    Archive[i].name = malloc(strlen(s[1]) + 1);
    strcpy(Archive[i].name, s[1]);

    Archive[i].surname = malloc(strlen(s[2]) + 1);
    strcpy(Archive[i].surname, s[2]);

    Archive[i].telephone = malloc(strlen(s[3]) + 1);
    strcpy(Archive[i].telephone, s[3]);

    i++;
  }

  *ne = i;
  fclose(f);
  return 1;
}

int main(void) {
  unsigned int ne;
  SPerson Archive[1000];
  Load(Archive, &ne);

  // Add code here to use the loaded data

  // Don't forget to free allocated memory for SPerson members when done
  for (int j = 0; j < ne; j++) {
    free(Archive[j].id);
    free(Archive[j].name);
    free(Archive[j].surname);
    free(Archive[j].telephone);
  }

  return 0;
}
