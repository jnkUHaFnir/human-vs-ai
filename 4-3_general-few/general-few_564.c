#include <stdio.h>
#include <string.h>

int main()
{
    char name[100];
    
    printf("Your name: \n");
    fgets(name, sizeof(name), stdin); // Read up to 99 characters (leaving space for null terminator)
    
    // Remove the newline character from the input if fgets includes it
    name[strcspn(name, "\n")] = '\0';
    
    printf("Name: %s\n", name);

    return 0;
}
