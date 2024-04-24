char inputName[10];
int i = 0;
// Dynamically allocate memory for names
name[0] = (char*)malloc(10 * sizeof(char));
name[1] = (char*)malloc(10 * sizeof(char));

while (i < 2)
{
    fgets(inputName, sizeof(inputName), stdin);
    char* pos = strchr(inputName, '\n');
    if (pos != NULL)
        *pos = '\0';
    strcpy(name[i], inputName); // Copy input into allocated memory
    i++;
}
printf("%s\n", name[0]); 
printf("%s\n", name[1]);
