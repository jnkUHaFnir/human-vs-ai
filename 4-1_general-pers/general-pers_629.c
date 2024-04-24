#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[100]; // Assuming the name will not exceed 100 characters
    int i;

    while (1) {
        printf("Enter your name: ");
        if (scanf("%99s", name) == 1) {
            int valid = 1;
            for (i = 0; i < strlen(name); i++) {
                if (!isalpha(name[i])) {
                    valid = 0;
                    printf("Invalid character. Please enter a valid name.\n");
                    break;
                }
            }
            if (valid) {
                // Convert all characters to lowercase
                for (i = 0; name[i]; i++) {
                    name[i] = tolower(name[i]);
                }
                // Capitalize the first letter
                name[0] = toupper(name[0]);
                
                // Print the transformed name
                printf("Transformed name: %s\n", name);
                break;
            }
        } else {
            printf("Please enter a valid name.\n");
            // Clear input buffer
            while ((getchar()) != '\n');
        }
    }

    return 0;
}
