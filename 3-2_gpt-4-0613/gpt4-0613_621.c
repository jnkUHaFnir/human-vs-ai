int Load(SPerson Archive[],unsigned int *ne) {
  int k,i=0;
  char s[4][20];
  FILE *f;
  f = fopen("archive.txt","r");
  if(f==NULL) return 0;

  while((k=fscanf(f,"%s %s %s %s",s[0],s[1],s[2],s[3]))==4) {
    Archive[i].id = malloc((strlen(s[0]) + 1) * sizeof(char));  // +1 for '\0' 
    strcpy(Archive[i].id, s[0]);
    Archive[i].name = malloc((strlen(s[1]) + 1) * sizeof(char));  // +1 for '\0' 
    strcpy(Archive[i].name, s[1]);
    Archive[i].surname = malloc((strlen(s[2]) + 1) * sizeof(char));  // +1 for '\0' 
    strcpy(Archive[i].surname, s[2]);
    Archive[i].telephone = malloc((strlen(s[3]) + 1) * sizeof(char));  // +1 for '\0' 
    strcpy(Archive[i].telephone, s[3]);
    i++;    
  }

  *ne = i;
  fclose(f);
  return 1;
}
//Free allocated memory
free(Archive[i].id);
free(Archive[i].name);
free(Archive[i].surname);
free(Archive[i].telephone);
