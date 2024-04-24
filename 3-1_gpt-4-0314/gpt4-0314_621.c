#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

typedef struct _SPerson {
  char *name;
  char *surname;
  char *id;
  char *telephone;
} SPerson;

void main(void) {
  unsigned int ne;
  SPerson Archive[1000];
  Load(Archive, &ne);
}

int Load(SPerson Archive[], unsigned int* ne) {
  int k, i = 0;
  char s[4][20];
  FILE* f;
  f = fopen("archive.txt", "r");
  if (f == 0) return 0;

  while ((k = fscanf(f, "%s %s %s %s", s[0], s[1], s[2], s[3])) == 4) {
    Archive[i].id = (char*)malloc(sizeof(char) * (strlen(s[0]) + 1)); // +1 for null terminator
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
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

typedef struct _SPerson
{
    char *name;
    char *surname;
    char *id;
    char *telephone;
} SPerson;

void main(void)
{
    unsigned int ne;
    SPerson Archive[1000];
    Load(Archive, &ne);
}

int Load(SPerson Archive[], unsigned int *ne)
{
    int i = 0;
    char line[100]; // Assuming a max line length of 100
    FILE *f;
    f = fopen("archive.txt", "r");
    if (f == 0)
        return 0;

    while (fgets(line, sizeof(line), f) != NULL)
    {
        Archive[i].id = (char *)malloc(20);
        Archive[i].name = (char *)malloc(20);
        Archive[i].surname = (char *)malloc(20);
        Archive[i].telephone = (char *)malloc(20);
        sscanf(line, "%s %s %s %s", Archive[i].id, Archive[i].name, Archive[i].surname, Archive[i].telephone);
        i++;
    }

    *ne = i;
    fclose(f);
    return 1;
}
