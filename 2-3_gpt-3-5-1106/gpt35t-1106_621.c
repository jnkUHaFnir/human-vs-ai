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
char line[100];
while (fgets(line, sizeof(line), f) != NULL) {
    char *token = strtok(line, " ");
    Archive[i].id = strdup(token);
    token = strtok(NULL, " ");
    Archive[i].name = strdup(token);
    token = strtok(NULL, " ");
    Archive[i].surname = strdup(token);
    token = strtok(NULL, " ");
    Archive[i].telephone = strdup(token);
    i++;
}
