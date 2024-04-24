Archive[i].id = (char*) malloc( sizeof(char) *strlen(s[0])); 
Archive[i].id = s[0];
// Allocate memory then copy the string
Archive[i].id = (char*) malloc(sizeof(char) * (strlen(s[0]) + 1));
strcpy(Archive[i].id, s[0]);

Archive[i].name = (char*) malloc(sizeof(char) * (strlen(s[1]) + 1));
strcpy(Archive[i].name, s[1]);

Archive[i].surname = (char*) malloc(sizeof(char) * (strlen(s[2]) + 1));
strcpy(Archive[i].surname, s[2]);

Archive[i].telephone = (char*) malloc(sizeof(char) * (strlen(s[3]) + 1));
strcpy(Archive[i].telephone, s[3]);
