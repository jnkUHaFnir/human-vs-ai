char inputName[10];
int i = 0;
while (i < 2)
{
    fgets(inputName, sizeof(inputName), stdin);
    char* pos = strchr(inputName, '\n');
    if (pos != NULL)
        *pos = '\0';
    
    name[i] = strdup(inputName); // Use strdup to allocate memory for each string
    i++;
}
printf("%s\n", name[0]);
printf("%s\n", name[1]);
