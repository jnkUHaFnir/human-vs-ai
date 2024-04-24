#include <stdio.h>

int main()
{
    char name[100];
    printf("Your name: \n");
    if (fgets(name, sizeof(name), stdin)) {
        // Remove newline that fgets reads if exists
        name[strcspn(name, "\n")] = 0; 
        printf("Name: %s  \n", name);
    } else {
        printf("Error reading name!\n");
    }

    return 0;
}
