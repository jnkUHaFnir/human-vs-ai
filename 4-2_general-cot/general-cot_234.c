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
    // Data loaded successfully, process here
  } else {
    // Error loading data
  }
  return 0;
}

int Load(SPerson Archive[], unsigned int *ne) {
  int i = 0;
  char s[4][20];
  FILE *f = fopen("archive.txt", "r");
  if (f == NULL) return 0;

  while (fscanf(f, "%19s %19s %19s %19s", s[0], s[1], s[2], s[3]) == 4) {
    Archive[i].id = malloc(strlen(s[0]) + 1); 
    Archive[i].name = malloc(strlen(s[1]) + 1); 
    Archive[i].surname = malloc(strlen(s[2]) + 1); 
    Archive[i].telephone = malloc(strlen(s[3]) + 1); 
    
    if (Archive[i].id && Archive[i].name && Archive[i].surname && Archive[i].telephone) {
      strcpy(Archive[i].id, s[0]);
      strcpy(Archive[i].name, s[1]);
      strcpy(Archive[i].surname, s[2]);
      strcpy(Archive[i].telephone, s[3]);
      
      i++;
    } else {
      // Memory allocation failed
      free(Archive[i].id);
      free(Archive[i].name);
      free(Archive[i].surname);
      free(Archive[i].telephone);
    }
  }

  *ne = i;
  fclose(f);
  return 1;
}
