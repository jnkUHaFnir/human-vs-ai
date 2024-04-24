for (int i = 0; i < 2; i++)
{
    fgets(inputName, sizeof(inputName), stdin);
    char* pos = strchr(inputName, '\n');
    if (pos != NULL)
        *pos = '\0';
    
    // Dynamically allocate memory and copy inputName
    name[i] = strdup(inputName);
}

printf("%s\n", name[0]);
printf("%s\n", name[1]);
