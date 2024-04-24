char* inputName = malloc(10);
// Check for malloc failure
while (i < 2)
{
    fgets(inputName, 10, stdin);
    // Copy input into dynamically allocated memory
    name[i] = strdup(inputName); 
    i++;
}
``` 

Remember to free the dynamically allocated memory when you are done using it.
