#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[50];
    int check;

    do {
        check = 0;
        printf("Please enter your name: ");
        scanf("%s", name);

        for (int i = 0; i < strlen(name); i++) {
            if (!isalpha(name[i])) {
                printf("Invalid character. Please enter a valid name.\n");
                check = 1;
                break;
            }
        }
    } while (check == 1);

    // Convert to standard case
    name[0] = toupper(name[0]);
    for(int i = 1; i < strlen(name); i++) {
        name[i] = tolower(name[i]);
        if (name[i-1] == ' ') {
            name[i] = toupper(name[i]);
        }
    }
    
    // Print result
    printf("Hello, %s!", name);

    return 0;
}
