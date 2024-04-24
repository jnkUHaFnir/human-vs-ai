#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _SPerson {
  char *name;
  char *surname;
  char *id;
  char *telephone;
} SPerson;

int Load(SPerson Archive[], unsigned int *ne);
void FreeArchive(SPerson Archive[], unsigned int ne);

int main(void) {
  unsigned int ne = 0;
  SPerson Archive[1000];
  if (Load(Archive, &ne)) {
    // Data loaded successfully
    for (unsigned int i = 0; i < ne; i++) {
      printf("ID: %s, Name: %s, Surname: %s, Telephone: %s\n",
             Archive[i].id, Archive[i].name, Archive[i].surname, Archive[i].telephone);
    }
    FreeArchive(Archive, ne); // Free allocated memory
  } else {
    printf("Error loading data from file.\n");
  }

  return 0;
}

int Load(SPerson Archive[], unsigned int *ne) {
  int k, i = 0;
  char s[4][20]; // Assuming max length of each string is 19 characters
  FILE *f;
  f = fopen("archive.txt", "r");
  if (f == NULL) return 0;

  while ((k = fscanf(f, "%19s %19s %19s %19s", s[0], s[1], s[2], s[3])) == 4) {
    Archive[i].id = strdup(s[0]);
    Archive[i].name = strdup(s[1]);
    Archive[i].surname = strdup(s[2]);
    Archive[i].telephone = strdup(s[3]);
    i++;
  }

  *ne = i;
  fclose(f);
  return 1;
}

void FreeArchive(SPerson Archive[], unsigned int ne) {
  for (unsigned int i = 0; i < ne; i++) {
    free(Archive[i].id);
    free(Archive[i].name);
    free(Archive[i].surname);
    free(Archive[i].telephone);
  }
}
