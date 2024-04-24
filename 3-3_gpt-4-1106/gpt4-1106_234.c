#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _SPerson {
  char *name;
  char *surname;
  char *id;
  char *telephone;
} SPerson;

int Load(SPerson Archive[],unsigned int *ne);

int main(void) { // main should have an int return type
  unsigned int ne;
  SPerson Archive[1000];
  if(Load(Archive,&ne)){
    printf("Data loaded successfully. Total records: %u\n", ne);
  } else {
    printf("Failed to load data.\n");
  }
  // Don't forget to free the allocated memory after you're done
  for (unsigned int i = 0; i < ne; ++i) {
    free(Archive[i].id);
    free(Archive[i].name);
    free(Archive[i].surname);
    free(Archive[i].telephone);
  }
  return 0; // Return 0 to indicate normal termination
}

int Load(SPerson Archive[], unsigned int *ne) {
  int k, i = 0;
  char s[4][20];
  FILE *f;
  f = fopen("archive.txt", "r");
  if (f == 0) return 0;

  while ((k = fscanf(f, "%19s %19s %19s %19s", s[0], s[1], s[2], s[3])) == 4) {
    Archive[i].id = (char*) malloc(sizeof(char) * (strlen(s[0]) + 1));
    strcpy(Archive[i].id, s[0]);
    Archive[i].name = (char*) malloc(sizeof(char) * (strlen(s[1]) + 1));
    strcpy(Archive[i].name, s[1]);
    Archive[i].surname = (char*) malloc(sizeof(char) * (strlen(s[2]) + 1));
    strcpy(Archive[i].surname, s[2]);
    Archive[i].telephone = (char*) malloc(sizeof(char) * (strlen(s[3]) + 1));
    strcpy(Archive[i].telephone, s[3]);
    i++;
  }

  *ne = i;
  fclose(f);
  return 1;
}
