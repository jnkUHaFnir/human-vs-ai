char* name[2];
//name[0] = (char*)malloc(sizeof(char*) * 10); 
//name[1] = (char*)malloc(sizeof(char*) * 10);
name[0] = "john";
name[1] = 'doe'; // This line is incorrect
char* name2[2] = { "emma", "olsson" };
for (int i = 0; i < 2; i++)
{
    name[i] = name2[i];
}
char inputName[10];
int i = 0; 
while (i < 2)
{
fgets(inputName, sizeof(inputName), stdin);
...
name[i++] = inputName;
}
