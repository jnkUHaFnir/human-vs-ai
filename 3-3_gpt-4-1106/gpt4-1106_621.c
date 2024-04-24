int Load(SPerson Archive[], unsigned int *ne) {
  int k, i = 0;
  char s[4][20];
  FILE *f;
  f = fopen("archive.txt", "r");
  if (f == NULL) return 0;

  while ((k = fscanf(f, "%19s %19s %19s %19s", s[0], s[1], s[2], s[3])) == 4) {
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
for (int j = 0; j < *ne; j++) {
  free(Archive[j].id);
  free(Archive[j].name);
  free(Archive[j].surname);
  free(Archive[j].telephone);
}
int Load(SPerson Archive[], unsigned int *ne); // Function prototype

int main(void) { // return type should be int
  unsigned int ne;
  SPerson Archive[1000];
  Load(Archive, &ne);

  // Remember to free the allocated memory when you're done

  return 0; // main should return an int
}
