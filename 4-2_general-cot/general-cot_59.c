char* name[2];
name[0] = "john";
name[1] = "doe"; // Corrected from single quotes to double quotes
printf("%s\n", name[0]);
printf("%s\n", name[1]);
char* name2[2] = { "emma", "olsson" };
char* name[2];
for (int i = 0; i < 2; i++)
{
    name[i] = name2[i];
}
printf("%s\n", name[0]);
printf("%s\n", name[1]);
char* name[2];
for (int i = 0; i < 2; i++)
{
    fgets(inputName, sizeof(inputName), stdin);
    // Remove newline character if present
    char* pos = strchr(inputName, '\n');
    if (pos != NULL)
        *pos = '\0';
    // Dynamically allocate memory for each name
    name[i] = (char*)malloc(strlen(inputName) + 1);
    strcpy(name[i], inputName);
}
// Use name to print the input names
printf("%s\n", name[0]);
printf("%s\n", name[1]);

// Free dynamically allocated memory at the end
for (int i = 0; i < 2; i++)
{
    free(name[i]);
}
