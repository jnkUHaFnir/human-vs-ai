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
  unsigned int ne;
  SPerson Archive[1000];
  Load(Archive, &ne);

  return 0;
}

int Load(SPerson Archive[], unsigned int *ne) {
  int k, i = 0;
  char s[4][20];
  FILE *f;
  f = fopen("archive.txt", "r");
  if (f == 0) return 0;

  while ((k = fscanf(f, "%s %s %s %s", s[0], s[1], s[2], s[3])) == 4) {
    Archive[i].id = (char*)malloc(sizeof(char) * (strlen(s[0]) + 1));
    strcpy(Archive[i].id, s[0]);
    Archive[i].name = (char*)malloc(sizeof(char) * (strlen(s[1]) + 1));
    strcpy(Archive[i].name, s[1]);
    Archive[i].surname = (char*)malloc(sizeof(char) * (strlen(s[2]) + 1));
    strcpy(Archive[i].surname, s[2]);
    Archive[i].telephone = (char*)malloc(sizeof(char) * (strlen(s[3]) + 1));
    strcpy(Archive[i].telephone, s[3]);
    i++;
  }

  *ne = i;
  fclose(f);
  return 1;
}