#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char* name[2];
    
    name[0] = "john";
    name[1] = "doe";
    printf("%s\n", name[0]); // prints john
    printf("%s\n", name[1]); // prints doe

    char* name2[2] = { "emma", "olsson" };
    printf("%s\n", name2[0]); // prints emma
    printf("%s\n", name2[1]); // prints olsson

    for (int i = 0; i < 2; i++)
    {
        name[i] = malloc(strlen(name2[i]) + 1); // Allocate memory for the string
        strcpy(name[i], name2[i]); // Copy the string from name2 to name
    }
    printf("%s\n", name[0]); // prints emma
    printf("%s\n", name[1]); // prints olsson

    char inputName[10];
    int i = 0;
    while (i < 2)
    {
        fgets(inputName, sizeof(inputName), stdin);
        char* pos = strchr(inputName, '\n');
        if (pos != NULL)
            *pos = '\0';

        name[i] = malloc(strlen(inputName) + 1); // Allocate memory for the string
        strcpy(name[i], inputName); // Copy the string from inputName to name[i]
      
        i++;
    }
    printf("%s\n", name[0]); // prints the first input
    printf("%s\n", name[1]); // prints the second input

    // Free allocated memory
    for (int i = 0; i < 2; i++) {
        free(name[i]);
    }

    return 0;
}
