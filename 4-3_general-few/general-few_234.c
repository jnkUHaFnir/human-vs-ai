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
  char line[100];
  char *token;

  FILE *f = fopen("archive.txt", "r");
  if (f == NULL) return 0;

  while (fgets(line, sizeof(line), f) != NULL) {
    Archive[i].id = strdup(strtok(line, " "));
    Archive[i].name = strdup(strtok(NULL, " "));
    Archive[i].surname = strdup(strtok(NULL, " "));
    Archive[i].telephone = strdup(strtok(NULL, " \n"));
    
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

  // Test printing loaded data
  for (int i = 0; i < ne; i++) {
    printf("ID: %s, Name: %s, Surname: %s, Telephone: %s\n", Archive[i].id, Archive[i].name, Archive[i].surname, Archive[i].telephone);
    free(Archive[i].id);
    free(Archive[i].name);
    free(Archive[i].surname);
    free(Archive[i].telephone);
  }

  return 0;
}
