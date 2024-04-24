#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char name[100];
    int i, check;

    do {
        printf("Please enter a valid name: ");
        scanf("%99s", name); // %99s to prevent buffer overflow

        check = 0;

        for(i = 0; i < strlen(name); i++) {
            if(!isalpha((unsigned char)name[i])) {
                printf("Invalid character. Please enter a valid name.\n");
                check = 1;
                break;
            }
        }
    } while(check);

    // rest of your code
    return 0;
}
for(i = 1; i < strlen(name); i++) {
    name[i] = tolower((unsigned char)name[i]);
}
name[0] = toupper((unsigned char)name[0]);

// For names with spaces (assuming names can have spaces)
int x = 1;
while(name[x] != '\0') {
    if(name[x-1] == ' ') {
        name[x] = toupper((unsigned char)name[x]);
    }
    x++;
}
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

int main() {
    char name[MAX_NAME_LENGTH];
    int check;

    do {
        printf("Please enter a valid name: ");
        scanf("%99s", name); // Preventing buffer overflow

        check = 0;
        for(int i = 0; i < strlen(name); i++) {
            if(!isalpha((unsigned char)name[i])) {
                printf("Invalid character. Please enter a valid name.\n");
                check = 1;
                break;
            }
        }
    } while(check);

    // Make all letters lowercase except the first.
    for(int i = 1; name[i]; i++) {
        name[i] = tolower((unsigned char)name[i]);
    }

    // First letter to uppercase
    name[0] = toupper((unsigned char)name[0]);

    // Uppercase letters following spaces (if you expect names with multiple parts)
    for(int i = 1; name[i]; i++) {
        if(name[i - 1] == ' ') {
            name[i] = toupper((unsigned char)name[i]);
        }
    }

    printf("Formatted name: %s\n", name);

    return 0;
}
