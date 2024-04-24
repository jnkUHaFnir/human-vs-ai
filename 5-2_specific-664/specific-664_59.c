#include <stdio.h>
#include <string.h>

int main() {
    char* name[2];
    name[0] = "john";
    name[1] = "doe";
    
    printf("%s\n", name[0]); // prints john
    printf("%c\n", name[1][0]); // prints d
    
    char* name2[2] = { "emma", "olsson" };
    printf("%s\n", name2[0]); // prints emma
    printf("%s\n", name2[1]); // prints olsson
    
    for (int i = 0; i < 2; i++) {
        name[i] = name2[i];
    }
    printf("%s\n", name[0]); // prints emma
    printf("%s\n", name[1]); // prints olsson
    
    char inputName[10];
    int i = 0;
    while (i < 2) {
        fgets(inputName, sizeof(inputName), stdin);
        char* pos = strchr(inputName, '\n');
        if (pos != NULL)
            *pos = '\0';
        name[i] = strdup(inputName); // using strdup to allocate separate memory for each name
        i++;
    }
    
    printf("%s\n", name[0]); 
    printf("%s\n", name[1]); 
  
    // Don't forget to free the dynamically allocated memory
    free(name[0]);
    free(name[1]);
    
    return 0;
}
