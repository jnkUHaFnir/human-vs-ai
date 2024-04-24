int Load(SPerson Archive[],unsigned int *ne) {
  int k,i=0;
  char s[4][20];
  FILE *f;
  f = fopen("archive.txt","r");
  if(f==0) return 0;

  while((k=fscanf(f,"%19s %19s %19s %19s",s[0],s[1],s[2],s[3]))==4) {
    Archive[i].id = (char*) malloc( sizeof(char) * (strlen(s[0])+1)); 
    strcpy(Archive[i].id, s[0]);
    Archive[i].name = (char*) malloc( sizeof(char) * (strlen(s[1])+1)); 
    strcpy(Archive[i].name, s[1]);
    Archive[i].surname = (char*) malloc( sizeof(char) * (strlen(s[2])+1)); 
    strcpy(Archive[i].surname, s[2]);
    Archive[i].telephone = (char*) malloc( sizeof(char) * (strlen(s[3])+1)); 
    strcpy(Archive[i].telephone, s[3]);
    i++;    
  }

  *ne = i;
  fclose(f);
  return 1;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELDS 4

typedef struct _SPerson {
  char *name;
  char *surname;
  char *id;
  char *telephone;
} SPerson;

void free_person(SPerson *person) {
  free(person->name);
  free(person->surname);
  free(person->id);
  free(person->telephone);
}

int split(char *str, char delim, char *fields[], int max_fields) {
  int count = 0;
  char *token = strtok(str, &delim);
  while (token != NULL && count < max_fields) {
    fields[count++] = token;
    token = strtok(NULL, &delim);
  }
  return count;
}

int load(SPerson archive[], int max_size) {
  FILE *f = fopen("archive.txt", "r");
  if (f == NULL) {
    perror("Failed to open file");
    return -1;
  }

  char line[MAX_LINE_SIZE];
  int i = 0;

  while (fgets(line, sizeof(line), f) != NULL && i < max_size) {
    line[strcspn(line, "\r\n")] = '\0'; // remove newline characters
    char *fields[MAX_FIELDS];
    int n_fields = split(line, ' ', fields, MAX_FIELDS);
    if (n_fields == MAX_FIELDS) {
      archive[i].id = strdup(fields[0]);
      archive[i].name = strdup(fields[1]);
      archive[i].surname = strdup(fields[2]);
      archive[i].telephone = strdup(fields[3]);
      i++;
    }
    else {
      fprintf(stderr, "Invalid line format: %s\n", line);
    }
  }

  fclose(f);
  return i;
}

int main() {
  SPerson archive[1000];
  int n_persons = load(archive, sizeof(archive)/sizeof(archive[0]));
  for (int i = 0; i < n_persons; i++) {
    printf("%s %s %s %s\n", archive[i].id, archive[i].name, archive[i].surname, archive[i].telephone);
    free_person(&archive[i]);
  }
  return 0;
}
