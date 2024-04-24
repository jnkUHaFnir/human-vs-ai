Archive[i].id = (char*) malloc( sizeof(char) * (strlen(s[0]) + 1));
strcpy(Archive[i].id, s[0]);
Archive[i].id = (char*) malloc(strlen(s[0]) + 1);
void Load(SPerson Archive[], unsigned int *ne);
