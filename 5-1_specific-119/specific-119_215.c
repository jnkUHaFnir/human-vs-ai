#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[50]; // Or any reasonable size
    int valid = 0;

    do {
        printf("Enter your name: ");
        scanf("%s", name);

        valid = 1;
        for (size_t i = 0; i < strlen(name); i++) {
            if (!isalpha(name[i])) {
                valid = 0;
                break;
            }
        }

        if (!valid) {
            printf("Invalid characters. Please enter a valid name.\n");
        }
    } while (!valid);

    // Process the valid name here

    return 0;
}
int x = 1;
name[0] = toupper(name[0]);

while (name[x] != '\0') {
    if (name[x - 1] == ' ') {
        name[x] = toupper(name[x]);
    } else {
        name[x] = tolower(name[x]);
    }
    x++;
}
