#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    printf("Your name: \n");
    
    if (fgets(name, sizeof(name), stdin) != NULL) {
        name[strcspn(name, "\n")] = 0; // Remove the newline character
        
        printf("Name: %s\n", name);
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}
