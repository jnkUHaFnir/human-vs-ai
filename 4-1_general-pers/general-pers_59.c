char* name[2];
name[0] = "john";
name[1] = "doe";
printf("%s\n", name[0]);
printf("%s\n", name[1]);
char* name[2];
char inputName[10];
int i = 0;
while (i < 2)
{
    fgets(inputName, sizeof(inputName), stdin);
    char* temp = malloc(strlen(inputName) + 1); // Allocate memory to store the input
    if (temp != NULL)
    {
        strcpy(temp, inputName); // Copy the input into the allocated memory
        name[i++] = temp; // Assign the copied input to name
    }
}
printf("%s\n", name[0]);
printf("%s\n", name[1]);
