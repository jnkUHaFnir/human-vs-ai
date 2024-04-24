#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int isValidName(const char* name) {
    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i])) {
            return 0;
        }
    }
    return 1;
}

void capitalizeName(char* name) {
    for (int i = 1; i < strlen(name); i++) {
        name[i] = tolower(name[i]);
    }
    name[0] = toupper(name[0]);

    int x = 1;
    while (name[x] != '\0') {
        if (name[x - 1] == ' ') {
            name[x] = toupper(name[x]);
        }
        x++;
    }
}

int main() {
    char name[100];
    int isValid = 0;

    do {
        printf("Enter a valid name: ");
        scanf("%s", name);
        isValid = isValidName(name);

        if (!isValid) {
            printf("Invalid characters. Please enter a valid name.\n");
        }
    } while (!isValid);

    capitalizeName(name);

    printf("Valid name: %s\n", name);
    
    return 0;
}
