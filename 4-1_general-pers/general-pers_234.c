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

int main(void) {
  unsigned int ne = 0;
  SPerson Archive[1000];
  if (Load(Archive, &ne)) {
    // Successfully loaded data
    // Use the loaded data as needed
  } else {
    // Failed to load data
  }

  return 0;
}

int Load(SPerson Archive[], unsigned int *ne) {
  int i = 0;
  FILE *f = fopen("archive.txt", "r");
  if (f == NULL) {
    return 0; // Unable to open file
  }

  while (fscanf(f, "%19s %19s %19s %19s", Archive[i].id, Archive[i].name, Archive[i].surname, Archive[i].telephone) == 4) {
    // Allocating memory and copying the content
    Archive[i].id = strdup(Archive[i].id);
    Archive[i].name = strdup(Archive[i].name);
    Archive[i].surname = strdup(Archive[i].surname);
    Archive[i].telephone = strdup(Archive[i].telephone);

    i++;
  }

  *ne = i;
  fclose(f);
  return 1; // Data loaded successfully
}
